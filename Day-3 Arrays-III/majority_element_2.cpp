#include<bits/stdc++.h>
using namespace std;

// using hashing
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second>n/3)
            {
                res.push_back(it.first);
            }
        }
        return res;
    }
};

// moore's voting algorithm extension
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0,cnt2=0;
        int ele1,ele2;
        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && nums[i]!=ele2)
            {
                cnt1++;
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1)
            {
                cnt2++;ele2=nums[i];
            }
            else if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
            else cnt1--,cnt2--;
        }
        vector<int> res;
        int me_cnt1=0,me_cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==ele1) me_cnt1++;
            else if(nums[i]==ele2) me_cnt2++;
        }
        if(me_cnt1>n/3) res.push_back(ele1);
        if(me_cnt2>n/3) res.push_back(ele2);
        return res;
    }
};