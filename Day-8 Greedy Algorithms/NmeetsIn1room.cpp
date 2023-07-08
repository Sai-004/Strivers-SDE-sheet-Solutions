#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> ftime;
        for(int i=0;i<n;i++)
        {
            ftime.push_back({end[i],start[i]});
        }
        sort(ftime.begin(),ftime.end());
        int cnt=1;
        int limit=ftime[0].first;
        for(int i=1;i<n;i++)
        {
            if(ftime[i].second>limit)
            {
                limit=ftime[i].first;
                cnt++;
            }
        }
        return cnt;
    }
};