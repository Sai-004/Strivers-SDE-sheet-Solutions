#include <bits/stdc++.h>
using namespace std;

// O(NlogN)
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = 1, curr = 1, prev = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == prev + 1)
            {
                curr++;
            }
            else if (nums[i] != prev)
                curr = 1;
            prev = nums[i];
            ans = max(ans, curr);
        }
        return ans;
    }
};

// O(N)
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        int longest = 1;
        for (auto it : s)
        {
            if (s.find(it - 1) == s.end())
            {
                int cnt = 1;
                int x = it;
                while (s.find(x + 1) != s.end())
                {
                    x++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};