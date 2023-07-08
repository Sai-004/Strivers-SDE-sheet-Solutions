#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    int lenL(ListNode *head)
    {
        int count = 1;
        ListNode *temp = head;
        while (temp && temp->next)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int length = lenL(head);
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *curr;
        ListNode *nex;
        while (length >= k)
        {
            curr = pre->next;
            nex = curr->next;
            for (int i = 1; i < k; i++)
            {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            length -= k;
        }
        return dummy->next;
    }
};