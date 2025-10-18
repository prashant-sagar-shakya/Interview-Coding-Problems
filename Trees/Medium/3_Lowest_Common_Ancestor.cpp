#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Given a binary tree, you need to find the lowest common ancestor (LCA) of two specified nodes, p and q. The LCA is defined as the lowest node in the tree that has both **p** and **q** as descendants, where a node is considered a descendant of itself. Your task is to identify and return this node.

struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == NULL || root == p || root == q) // Base Case: If root is null or root is one of the node's we are looking for
        return root;

    // Recursively search for left and right subtrees
    Node *left = lowestCommonAncestor(root->left, p, q);
    Node *right = lowestCommonAncestor(root->right, p, q);

    // If left is NULL it means both p and q are in right subtree
    if (left == NULL)
        return right;

    // If right is NULL it means both p and q are in left subtree
    else if (right == NULL)
        return left;

    //  If both are not NULL
    else
        return root;
}

// Your code here
void Solve()
{
    // Constructing the tree
    /*
                3
              /   \
             5     1
            / \   / \
           6   2 0   8
              / \
             7   4
    */
    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    // Nodes to find LCA for
    Node *p = root->left;  // Node with value 5
    Node *q = root->right; // Node with value 1

    Node *lca = lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->data << " and " << q->data << " is: " << lca->data << "\n";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}