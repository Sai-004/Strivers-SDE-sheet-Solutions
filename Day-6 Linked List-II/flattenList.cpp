#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;
    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *mergeL(Node *a, Node *b)
{
    Node *temp = new Node(-1);
    Node *res = temp;
    while (a && b) {
        if (a->data > b->data) {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
        else {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
    }
    if (a) temp->bottom = a;
    if (b) temp->bottom = b;
    return res->bottom;
}

Node *flatten(Node *root)
{
    if (!root || !root->next) return root;
    root->next = flatten(root->next);
    root = mergeL(root, root->next);
    return root;
}