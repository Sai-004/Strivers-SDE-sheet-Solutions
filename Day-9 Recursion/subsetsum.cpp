#include<bits/stdc++.h> 
using namespace std;

class Solution
{
public:
    void rec(int index,int sum,vector<int> &arr,int N,vector<int>& res)
    {
        if(index==N)
        {
            res.push_back(sum);
            return;
        }
        rec(index+1,sum+arr[index],arr,N,res);
        rec(index+1,sum,arr,N,res);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        rec(0,0,arr,N,res);
        sort(res.begin(),res.end());
        return res;
    }
};