#include<bits/stdc++.h>
using namespace std;

// TC O(n); SC O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        int j=0;
        for(auto it:s)
        {
            nums[j++]=it;
        }
        return s.size();
    }
};

// TC O(n); SC O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=nums[count])
            {
                count++;
                nums[count]=nums[i];
            }
        }
        return count+1;
    }
};