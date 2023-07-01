#include<bits/stdc++.h>
using namespace std;

// using hashing
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;                    // O(N logN)
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second>(nums.size()/2))
            {
                return it.first;
            }
        }
        return -1;
    }
};

// moore's voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt=0,me=-1;
        for(int i=0;i<n;i++)            // O(N)
        {
            if(cnt==0)
            {
                cnt++,me=nums[i];
            }
            else if(nums[i]==me) cnt++;
            else cnt--;
        }
        return me;

        // checking if the majority element actually exists.
        // int me_cnt=0;
        // for(int i=0;i<n;i++)             //O(N)
        // {
        //     if(me==nums[i]) me_cnt++;
        // }
        // if(me_cnt>(n/2)) return me;
        // else return -1;
    }
};