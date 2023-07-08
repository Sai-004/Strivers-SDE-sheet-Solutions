#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    bool static comparision (Item a,Item b)
    {
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comparision);
        double tv=0;int currW=0;
        for(int i=0;i<n;i++)
        {
            if(currW+arr[i].weight<=W)
            {
                currW+=arr[i].weight;
                tv+=arr[i].value;
            }
            else
            {
                int rW=W-currW;
                tv+=((double) arr[i].value / (double) arr[i].weight) * (double) rW;
                break;
            }
        }
        return tv;
    }
        
};