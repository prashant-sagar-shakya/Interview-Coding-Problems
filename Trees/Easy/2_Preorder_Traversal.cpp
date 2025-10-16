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

void Pre_Order(node *root)
{
    // Root, Left, Right
    if (root != nullptr)
    {
        cout << root->data << " ";
        Pre_Order(root->left);
        Pre_Order(root->right);
    }
}

// Your code here
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
    Pre_Order(root);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}