#include<bits/stdc++.h>
using namespace std;

// brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// hashing
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int,int> mp;
            for (int i = 0; i < nums.size(); i++)
            {
                int sum=target-nums[i];
                if (mp.find(sum)!=mp.end())
                {
                    return {mp[sum],i};
                }
                mp[nums[i]]=i;
            }
            return {};
        }
};