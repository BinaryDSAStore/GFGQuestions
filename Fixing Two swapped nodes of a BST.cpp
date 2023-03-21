#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *correctBST(struct Node *root)
{
    if (!root)
        return root;
    Node *prev = NULL, *first = NULL, *second = NULL;
    stack<Node *> s;
    Node *curr = root;
    while (curr || !s.empty())
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        if (prev && prev->data > curr->data)
        {
            if (!first)
                first = prev;
            second = curr;
        }
        prev = curr;
        curr = curr->right;
    }
    swap(first->data, second->data);
    return root;
}