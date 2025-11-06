#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

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

// Function to check if two subtrees are mirror images of each other
bool isMirror(node *left, node *right)
{
    // If both subtrees are NULL, they are mirror images
    if (!left && !right)
        return true;

    // If one of them is NULL (and the other isn't), they are not mirrors
    if (!left || !right)
        return false;

    // Check three conditions:
    // 1. The current node values are equal
    // 2. The left subtree of one is a mirror of the right subtree of the other
    // 3. The right subtree of one is a mirror of the left subtree of the other
    return (left->data == right->data) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Function to check if a binary tree is symmetric
bool isSymmetric(node *root)
{
    // An empty tree is symmetric
    if (!root)
        return true;

    // Check if the left and right subtrees are mirrors of each other
    return isMirror(root->left, root->right);
}

// Your code here
void Solve()
{
    /*
             1
           /   \
          2     2
         / \   / \
        3  4  4  3
    */

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    root->right->right = new node(3);

    cout << boolalpha << isSymmetric(root);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}