#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Given a binary tree, determine if it is height - balanced.
// A height - balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

struct node
{
    int data;
    node *left, *right;
    node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

// Function to calculate the maximum depth (height) of the binary tree
int maxDepth(node *root)
{
    // Base case: if node is NULL, height is 0
    if (!root)
        return 0;

    // Recursively find height of left and right subtrees
    int n = maxDepth(root->left);
    int m = maxDepth(root->right);

    // Height of current node = 1 + max(left height, right height)
    return 1 + max(n, m);
}

// Function to check if the binary tree is height-balanced
bool isBalanced(node *root)
{
    // Base case: an empty tree is always balanced
    if (!root)
        return true;
    // Compute height of left and right subtrees
    int hl = maxDepth(root->left);
    int hr = maxDepth(root->right);

    // If height difference > 1, tree is not balanced
    if (abs(hl - hr) > 1)
        return false;
    // Recursively check if both left and right subtrees are balanced
    if (!isBalanced(root->left) || !isBalanced(root->right))
        return false;

    return true;
}

// Your code here
void Solve()
{
    /*
              10
             /  \
            20   30
           / \
          40  50
    */

    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);

    cout << boolalpha << isBalanced(root);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}