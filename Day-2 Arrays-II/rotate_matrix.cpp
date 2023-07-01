#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &A)
    {
        int N = A.size();
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = i; j < N - i - 1; j++)
            {
                int temp = A[i][j];
                A[i][j] = A[N - 1 - j][i];
                A[N - 1 - j][i] = A[N - 1 - i][N - 1 - j];
                A[N - 1 - i][N - 1 - j] = A[j][N - 1 - i];
                A[j][N - 1 - i] = temp;
            }
        }
    }
};

// other solution
// void rotate(vector<vector<int>> &A)
// {
//     int n=A.size();
//     // transpose
//     for (int i = 0; i < n-1; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             swap(A[i][j],A[j][i]);
//         }
//     }
//     // reverse
//     for (int i = 0; i < n; i++)
//     {
//         reverse(A[i].begin(),A[i].end());
//     }
// }