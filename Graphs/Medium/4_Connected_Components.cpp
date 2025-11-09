#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Perform DFS traversal to mark all nodes in the same component
void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    // Explore all nodes connected to this node
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[node][i] && !visited[i])
            dfs(i, graph, visited);
    }
}

// Count connected components in an undirected graph
int countConnectedComponents(vector<vector<int>> &graph)
{
    int n = graph.size();
    int components = 0;
    vector<bool> visited(n, false);
    // For every unvisited node, start a new DFS
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            components++;
            dfs(i, graph, visited);
        }
    }
    return components;
}

// Your code here
void Solve()
{
    vector<vector<int>> graph = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << "Number of Connected Components: " << countConnectedComponents(graph) << endl;
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}