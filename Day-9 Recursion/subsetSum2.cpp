#include <bits/stdc++.h>
using namespace std;
// pending
// class Solution
// {
// public:
//     void fun(vector<int> &nums, int index, vector<int> temp, set<vector<int>> &res)
//     {
//         if (index == nums.size())
//         {
//             sort(temp.begin(), temp.end());
//             res.insert(temp);
//             return;
//         }
//         temp.push_back(nums[index]);
//         fun(nums, index + 1, temp, res);
//         temp.pop_back();
//         fun(nums, index + 1, temp, res);
//     }
//     vector<vector<int>> subsetsWithDup(vector<int> &nums)
//     {
//         vector<vector<int>> ans;
//         set<vector<int>> res;
//         vector<int> temp;
//         fun(nums, 0, temp, res);
//         for (auto it = res.begin(); it != res.end(); it++)
//         {
//             ans.push_back(*it);
//         }
//         return ans;
//     }
// };