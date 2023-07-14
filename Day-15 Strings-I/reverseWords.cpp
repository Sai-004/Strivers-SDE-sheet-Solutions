#include <bits/stdc++.h>
using namespace std;

// extra space
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> words;
        string temp = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                temp += s[i];
            }
            else if (temp != "")
            {
                words.push_back(temp);
                temp = "";
            }
        }
        if (temp != "")
        {
            words.push_back(temp);
        }
        temp = "";
        reverse(words.begin(), words.end());
        for (int i = 0; i < words.size() - 1; i++)
        {
            temp += words[i];
            temp += " ";
        }
        temp += words[words.size() - 1];
        return temp;
    }
};

// No extra space
class Solution
{
public:
    string reverseWords(string s)
    {
        string temp = "", ans = "";
        int l = 0, r = s.length() - 1;
        while (l <= r)
        {
            if (s[l] != ' ')
            {
                temp += s[l];
            }
            else if (temp != "")
            {
                if (ans == "")
                    ans = temp;
                else
                    ans = temp + " " + ans;
                temp = "";
            }
            l++;
        }
        if (temp != "")
        {
            if (ans == "")
                ans = temp;
            else
                ans = temp + " " + ans;
        }
        return ans;
    }
};