#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findss(int ind,vector<int>& nums,int target,vector<vector<int>>& ans,vector<int> ds)
    {
        if(ind==nums.size())
        {
            if(target==0)
                ans.push_back(ds);
            return;
        }
        if(nums[ind]<=target)
        {
            ds.push_back(nums[ind]);
            findss(ind,nums,target-nums[ind],ans,ds);
            ds.pop_back();
        }
        findss(ind+1,nums,target,ans,ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;vector<int>ds;
        findss(0,candidates,target,ans,ds);
        return ans;
    }
};