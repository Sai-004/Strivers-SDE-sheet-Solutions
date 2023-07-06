#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// store and check
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> ll;
        while (head)
        {
            ll.push_back(head->val);
            head = head->next;
        }
        int mid = (ll.size() + 1) / 2;
        for (int i = 0; i < mid; i++)
        {
            if (ll[i] != ll[ll.size() - 1 - i])
                return false;
        }
        return true;
    }
};

// reverse after half
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverse(slow->next);
        ListNode *temp = head;
        slow = slow->next;
        while (slow)
        {
            if (slow->val != temp->val)
                return false;
            slow = slow->next;
            temp = temp->next;
        }
        return true;
    }
    ListNode *reverse(ListNode *curr)
    {
        ListNode *nex = NULL;
        ListNode *pre = NULL;
        while (curr)
        {
            nex = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nex;
        }
        return pre;
    }
};