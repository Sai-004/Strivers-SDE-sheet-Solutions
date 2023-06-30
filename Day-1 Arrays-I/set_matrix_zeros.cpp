#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        set<int> zero_x,zero_y;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    zero_x.insert(i);
                    zero_y.insert(j);
                }
            }
        }
        for(auto i:zero_x)
        {
            for(int j=0;j<m;j++)
            {
                matrix[i][j]=0;
            }
        }
        for(auto i : zero_y)
        {
            for(int j=0;j<n;j++)
            {
                matrix[j][i]=0;
            }
        }
    }
};