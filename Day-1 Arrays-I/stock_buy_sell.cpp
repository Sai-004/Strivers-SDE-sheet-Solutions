#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // we can sell only if we buy so let's take this to our advantage
        // so for every index we visit we will take trak of minimum price till that day
        int mini = prices[0];
        int n = prices.size();
        int profit = 0;
        for (int i = 1; i < n; i++)
        {
            mini = min(mini, prices[i]);
            int pr = prices[i] - mini;
            profit = max(profit, pr);
        }
        return profit;
    }
};