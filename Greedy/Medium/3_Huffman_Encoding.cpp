#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
// Note : While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

// Approach:
// Create a leaf node for each character and its frequency.
// Push all nodes into a min-heap sorted by frequency.
// While more than one node in the heap, pop two smallest nodes and merge them into a new internal node, then push it back.
// Assign the smaller frequency/first node as left child and the other as right child during merging.
// After merging, the remaining node is the root of the Huffman tree.
// Traverse the tree in preorder, appending '0' for left and '1' for right, storing codes at leaf nodes.
// Collect and return all Huffman codes in preorder order.

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparison for priority queue
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        if (a->freq == b->freq)
            return a->ch > b->ch; // smaller char goes left if frequency same
        return a->freq > b->freq; // min heap based on frequency
    }
};

// Recursive function to generate codes in preorder traversal
void generateCodes(Node *root, string code, vector<string> &res, unordered_map<char, string> &mp)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    { // leaf node
        mp[root->ch] = code;
        res.push_back(code);
    }

    generateCodes(root->left, code + "0", res, mp);
    generateCodes(root->right, code + "1", res, mp);
}

vector<string> huffmanCodes(string S, vector<int> f, int N)
{
    priority_queue<Node *, vector<Node *>, Compare> pq;

    for (int i = 0; i < N; i++)
        pq.push(new Node(S[i], f[i]));

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *parent = new Node('$', left->freq + right->freq); // '$' for internal node
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    Node *root = pq.top();

    vector<string> res;
    unordered_map<char, string> mp;
    generateCodes(root, "", res, mp);

    return res;
}

// Your code here
void Solve()
{
    string s;
    cin >> s;
    int N = s.length();
    vector<int> f(N);
    for (int &i : f)
        cin >> i;
    vector<string> res = huffmanCodes(s, f, N);
    for (string i : res)
        cout << i << " ";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}