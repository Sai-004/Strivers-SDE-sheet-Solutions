#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);sort(dep,dep+n);
    	int cnt=1,res=1;
    	int i=1,j=0;
    	while(i<n&&j<n)
    	{
    	    if(arr[i]<=dep[j]) cnt++,i++;
    	    else cnt--,j++;
    	    res=max(res,cnt);
    	}
    	return res;
    }
};