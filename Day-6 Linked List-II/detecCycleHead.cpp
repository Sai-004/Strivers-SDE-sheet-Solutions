#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// hashing
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hash;
        while(head)
        {
            if(hash.find(head)!=hash.end()) return head;
            hash.insert(head);
            head=head->next;
        }
        return NULL;
    }
};

// Optimal
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL||head->next == NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* start=head;
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            {
                while(slow!=start)
                {
                slow=slow->next;
                start=start->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};