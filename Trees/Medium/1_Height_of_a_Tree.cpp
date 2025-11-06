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

// Function to calculate height (maximum depth) of a binary tree
int maxHeight(node *root)
{
    // Base condition:
    // If the current node is NULL, it means we have reached beyond a leaf node.
    // So, return 0 because NULL has no height.
    if (!root)
        return 0;

    // Recursively find the height of the left subtree
    int left = maxHeight(root->left);
    // Recursively find the height of the right subtree
    int right = maxHeight(root->right);

    // The height of the current node is:
    // 1 (for the current node itself) + maximum of left and right subtree heights
    return max(left, right) + 1;
}

void Solve()
{
    /*
                10
             /    \
           20      60
          /  \    /  \
        30   90  80   15
          \
           40
    */
    node *root = new node(10);
    root->left = new node(20);
    root->left->left = new node(30);
    root->left->right = new node(90);
    root->left->left->right = new node(40);
    root->right = new node(60);
    root->right->left = new node(80);
    root->right->right = new node(15);

    cout << "Height of Tree: " << maxHeight(root) << endl;
}

// Your code here
void Solve()
{
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}