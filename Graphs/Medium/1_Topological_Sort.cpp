#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<int> topologicalSort(int n, vector<vector<int>> &edges)
{
    // Create adjacency list for the directed graph
    vector<vector<int>> graph(n);
    // Create indegree array to count incoming edges for each node
    vector<int> indegree(n, 0);
    // Build the graph and fill indegree
    for (auto &edge : edges)
    {
        int u = edge[0]; // from node
        int v = edge[1]; // to node
        graph[u].push_back(v);
        indegree[v]++;
    }
    // Initialize queue with all nodes having indegree 0
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    // Store topological order
    vector<int> topoOrder;
    // Process queue until empty
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);
        // Reduce indegree of all adjacent nodes
        for (int neighbor : graph[node])
        {
            indegree[neighbor]--;
            // If indegree becomes 0, push to queue
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    // If topological sort includes all nodes → valid
    if (topoOrder.size() == n)
        return topoOrder;
    else
        return {}; // Cycle detected
}

// Your code here
void Solve()
{
    int n = 6; // number of nodes
    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};
    vector<int> result = topologicalSort(n, edges);
    cout << "Topological Order: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}