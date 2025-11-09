#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// DFS function to detect a cycle in a directed graph
bool dfs(int node, const vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &path)
{
    // Mark current node as visited and include it in the recursion stack
    vis[node] = true;
    path[node] = true;
    // Traverse all adjacent nodes
    for (int next : adj[node])
    {
        // If neighbor not visited, recursively visit it
        if (!vis[next])
        {
            if (dfs(next, adj, vis, path))
                return true; // Cycle found in this DFS path
        }
        // If neighbor already in the current recursion stack → cycle detected
        else if (path[next])
            return true;
    }
    // Backtrack: remove current node from recursion stack
    path[node] = false;
    return false; // No cycle found through this node
}

// Function to check if graph has a cycle
bool canFinish(int n, vector<vector<int>> &edges)
{
    // Build adjacency list for directed graph
    vector<vector<int>> adj(n);
    for (auto &e : edges)
    {
        int u = e[1];        // prerequisite
        int v = e[0];        // dependent
        adj[u].push_back(v); // edge: u → v
    }
    // Create visited and recursion stack arrays
    vector<bool> vis(n, false);
    vector<bool> path(n, false);
    // Run DFS for all unvisited nodes
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, path))
                return false; // Cycle found → cannot finish all nodes
        }
    }
    // If DFS completed for all nodes → no cycle
    return true;
}

// Your code here
void Solve()
{
    int n = 4;
    vector<vector<int>> edges = {{1, 0}, {2, 1}, {3, 2}, {1, 3}}; // This has a cycle
    bool possible = canFinish(n, edges);
    if (possible)
        cout << "No cycle detected. All nodes can be completed." << endl;
    else
        cout << "Cycle detected. Cannot complete all nodes." << endl;
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}