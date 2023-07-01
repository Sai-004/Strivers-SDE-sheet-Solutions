#include<bits/stdc++.h>
using namespace std;

long long findKthPositive(vector<long long>& arr, long long k) {
    long long l = 0;
    long long r = arr.size();

    while (l < r) {
        const long long m = (l + r) / 2;
        if (arr[m] - m - 1 >= k)
        r = m;
        else
        l = m + 1;
    }
    return l + k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,q;cin>>n>>q;
    vector<long long> removed;

    for (long long i = 0; i < n; i++)
    {
        long long c;cin>>c;
        removed.push_back(c);
    }
    while (q--)
    {
        long long t;cin>>t;
        long long index=findKthPositive(removed,t);
        cout<<index<<endl;
    }
    
    
    return 0;
}
/*
    1 2 3 4 5 6 7 8 9
        x   x x x    
    3 5 6 7
    2 --> 2
    5 --> 9
    3 --> 4

*/