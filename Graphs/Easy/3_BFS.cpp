#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<int> BFS(vector<int> adjMat[], int n)
{
    vector<int> vis(n, 0); // visited array to mark visited nodes
    vis[0] = 1;            // Marking starting node as visited
    queue<int> q;
    q.push(0);       // Start BFS from node 0
    vector<int> bfs; // A vector to store traversal result
    while (!q.empty())
    {
        int node = q.front(); // Get the front node from queue
        q.pop();              // Remove it from the queue
        bfs.push_back(node);  // Adding the current node to bfs result
        for (auto i : adjMat[node])
        {                // Traverse all adjacent nodes
            if (!vis[i]) // if the node isn't visited
            {
                vis[i] = 1; // mark it visited
                q.push(i);  // Add it to queue
            }
        }
    }
    return bfs;
}

// Your code here
void Solve()
{
    int n, m;
    cin >> n >> m; // number of vertices and edges
    vector<int> adjMat[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u].push_back(v);
        adjMat[v].push_back(u); // for undirected graph
    }
    vector<int> bfsOrder = BFS(adjMat, n);

    // Printing BFS traversal
    for (int node : bfsOrder)
        cout << node << " ";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}