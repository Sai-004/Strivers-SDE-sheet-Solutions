#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    long long p = n;
    if (p == 0)
        return 1.0;
    if (x == 0.0)
        return 0.0;
    if (p < 0)
    {
        x = 1 / x;
        p = -p;
    }
    double result = 1.0;
    while (p > 0)
    {
        if (p % 2 == 1)
            result *= x;
        x *= x;
        p /= 2;
    }
    return result;
}
