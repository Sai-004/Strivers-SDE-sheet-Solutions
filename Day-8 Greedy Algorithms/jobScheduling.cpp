#include<bits/stdc++.h>
using namespace std; 

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

class Solution 
{
    public:
    
    bool static comparision(Job a,Job b)
    {
        return (a.profit>b.profit);
    }

    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comparision);
        int max_d=arr[0].dead;
        for(int i=1;i<n;i++)
        {
            max_d=max(max_d,arr[i].dead);
        }
        vector<int> slot(max_d+1,-1);int cnt=0,profitt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(slot[j]==-1)
                {
                    slot[j]=i;
                    profitt+=arr[i].profit;
                    cnt++;
                    break;
                }
            }
        }
        return {cnt,profitt};
    }
};