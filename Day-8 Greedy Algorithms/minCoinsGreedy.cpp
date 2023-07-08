#include <bits/stdc++.h>
using namespace std;

// Greedy method // works only if coins[i-1]+coins[i-2]<coins[i]
int findMinimumCoins(int amount) 
{
    vector<int> coins={1,2,5,10,20,50,100,500,1000};
    int MinCoins=0;
    int i = coins.size()-1;
    while(amount&& i>=0)
    {
        if(amount<coins[i])
        {
            i--;
            continue;
        }
        MinCoins++;
        amount-=coins[i];
    }
    return MinCoins;
}

// DP method // works for all cases
int minCoins(vector<int> coins, int n, int amount)
{
	int table[amount + 1];

	// Base case (If given amount amount is 0)
	table[0] = 0;

	// Initialize all table values as Infinite
	for (int i = 1; i <= amount; i++)
		table[i] = INT_MAX;

	// Compute minimum coins required for all
	// values from 1 to amount
	for (int i = 1; i <= amount; i++) {
		// Go through all coins smaller than i
		for (int j = 0; j < n; j++)
			if (coins[j] <= i) {
				int sub_res = table[i - coins[j]];
				if (sub_res != INT_MAX
					&& sub_res + 1 < table[i])
					table[i] = sub_res + 1;
			}
	}

	if (table[amount] == INT_MAX)
		return -1;

	return table[amount];
}

int main()
{
	vector<int> coins = { 9, 6, 5, 1 };
	int n = coins.size();
	int amount = 11;
	cout << "Minimum coins required is "
		<< minCoins(coins, n, amount);
	return 0;
}
