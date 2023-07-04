#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// direct approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            n++;
        }
        temp=head;
        for(int i=0;i<n/2;i++)
        {
            temp=temp->next;
        }
        return temp;
    }
};

// Tortoise-Hare approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
};