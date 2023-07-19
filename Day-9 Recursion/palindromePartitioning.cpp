#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void partitioncheck(int ind,string s,vector<string>&temp,vector<vector<string>>& ans)
    {
        if(ind==s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(isPalindrome(s,ind,i))
            {
                temp.push_back(s.substr(ind,i-ind+1));
                partitioncheck(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string s,int start,int end)
    {
        while(start<end)
        {
            if(s[start]==s[end])
            {
                start++,end--;
            }
            else return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string>temp;vector<vector<string>> ans;
        partitioncheck(0,s,temp,ans);
        return ans;
    }
};