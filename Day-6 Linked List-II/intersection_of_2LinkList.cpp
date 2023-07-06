#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B)
    {
        int l1 = 0, l2 = 0;
        ListNode *temp = A;
        while (temp)
        {
            l1++;
            temp = temp->next;
        }
        temp = B;
        while (temp)
        {
            l2++;
            temp = temp->next;
        }
        ListNode *a1 = A;
        ListNode *b1 = B;
        int dif = abs(l1 - l2);
        if (l1 > l2)
        {
            while (dif--)
            {
                a1 = a1->next;
            }
        }
        else
        {
            while (dif--)
            {
                b1 = b1->next;
            }
        }
        while (a1 != b1 and a1 != NULL and b1 != NULL)
        {
            a1 = a1->next;
            b1 = b1->next;
        }
        if (b1 == NULL)
            return b1;
        return a1;
    }
};