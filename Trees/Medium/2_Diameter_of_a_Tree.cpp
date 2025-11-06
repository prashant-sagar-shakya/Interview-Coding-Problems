#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// The diameter of a binary tree is defined as the longest path between any two nodes, measured by the number of edges on that path; this path can go through or bypass the root.To find it, we perform a depth - first traversal(DFS) where for every node, we calculate the height of its left and right subtrees — the sum of these heights gives the longest path passing through that node. The maximum of all such paths across nodes is the tree’s diameter.

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

// Utility function that returns the height of the tree and simultaneously updates the diameter value
int diameterUtil(node *root, int &diameter)
{
    // Base case: if node is NULL, height is 0
    if (!root)
        return 0;

    // Recursively find height of left subtree
    int left = diameterUtil(root->left, diameter);
    // Recursively find height of right subtree
    int right = diameterUtil(root->right, diameter);
    // The path that passes through this node is left_height + right_height
    // Update the diameter if this path is the longest so far
    diameter = max(diameter, left + right);
    // Return the height of this node = 1 + max(left, right)
    return max(left, right) + 1;
}

// Function to calculate the diameter of binary tree
int diameterOfTree(node *root)
{
    int diameter = 0;             // variable to store the maximum diameter found
    diameterUtil(root, diameter); // helper function call
    return diameter;              // returns the number of edges in the longest path
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

    cout << "Diameter of Tree: " << diameterOfTree(root) << endl;
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}