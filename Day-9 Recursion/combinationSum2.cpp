#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findss(int ind,int target,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) return;
            ds.push_back(nums[i]);
            findss(i+1,target-nums[i],nums,ds,ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;vector<int> ds;
        findss(0,target,candidates,ds,ans);
        return ans;
    }
};