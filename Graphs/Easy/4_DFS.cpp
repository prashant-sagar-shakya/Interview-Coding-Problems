#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void dfs(int node, vector<int> adjMat[], vector<int> &vis, vector<int> &result)
{
    vis[node] = 1;          // Mark current node as visited
    result.push_back(node); // Adding the ndoe to the result list
    for (auto i : adjMat[node])
    {
        // Visit all unvisited neighbors
        if (!vis[i])
            dfs(i, adjMat, vis, result);
    }
}

vector<int> DFS_Traversal(vector<int> adjMat[], int n)
{
    vector<int> vis(n, 0);
    int start = 0;
    vector<int> result;
    dfs(start, adjMat, vis, result);
    return result;
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
    vector<int> dfsOrder = DFS_Traversal(adjMat, n);

    // Printing DFS traversal
    for (int node : dfsOrder)
        cout << node << " ";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}