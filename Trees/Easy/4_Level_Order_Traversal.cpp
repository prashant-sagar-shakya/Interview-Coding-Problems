#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

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

vector<vector<int>> Level_Order(Node *root)
{
    vector<vector<int>> Traversal;
    if (root == nullptr) // If tree is empty return ans
        return Traversal;
    queue<Node *> q; // Using a queue to process level by level
    q.push(root);    // Start by oushing root into queue
    while (!q.empty())
    {
        // Keep going while there're Nodes remaining in the queue
        int size = q.size(); // no. of Nodes at current level
        vector<int> level;   // Vector to store current level Nodes values
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front(); // Get the front node from queue and remove it
            q.pop();
            // Add Left and Right Child if Exists
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
            // Save the current Nodevalue
            level.push_back(curr->data);
        }
        Traversal.push_back(level); // Add current level to final traversal
    }
    return Traversal;
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
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(30);
    root->left->right = new Node(90);
    root->left->left->right = new Node(40);
    root->right = new Node(60);
    root->right->left = new Node(80);
    root->right->right = new Node(15);
    vector<vector<int>> Traversal = Level_Order(root);

    // Printing the Level Order Traversal
    for (auto traverse : Traversal)
    {
        for (int &i : traverse)
            cout << i << " ";
        cout << endl;
    }
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}