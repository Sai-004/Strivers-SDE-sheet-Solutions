#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> hash(n,0);
        for(int i=0;i<n;i++)
        {
            if(hash[nums[i]]==1)
            {
                return nums[i];
            }
            else hash[nums[i]]++;
        }
        return 0;
    }
};