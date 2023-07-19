#include <bits/stdc++.h>
using namespace std;

int comb(int n, int r)
{
    if (n < r) return 0;
    if (r == 0) return 1;
    if (r == 1) return n;
    if (n == 1) return 1;
    return comb(n - 1, r - 1) + comb(n - 1, r);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> mp(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            int x = s[i] - 'a';
            mp[x] += 1;
        }
        sort(mp.begin(), mp.end(), greater<int>());
        int ans = 1;
        for (int i = 0; i < k; i++)
        {
            ans *= mp[i];
        }
        // cout<<ans<<" ";
        int tot = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp[i] == mp[k - 1])
            {
                tot++;
            }
        }
        int taken = 0;
        for (int i = 0; i < k; i++)
        {
            if (mp[i] == mp[k - 1])
            {
                taken++;
            }
        }
        ans *= comb(tot, taken);
        cout << ans << endl;
    }

    return 0;
}