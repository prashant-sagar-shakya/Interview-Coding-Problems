#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

bool hasCycle(int n, vector<vector<int>> &edges)
{
    // Create adjacency list
    vector<vector<int>> adj(n);
    // Create indegree array to track number of incoming edges
    vector<int> indegree(n, 0);
    // Build the graph and calculate indegrees
    for (auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }
    // Initialize a queue with all nodes having indegree 0
    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (indegree[i] == 0)
            q.push(i);
    // Keep count of processed nodes
    int processed = 0;
    // Process nodes in topological order
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        processed++;

        // Decrease indegree of all adjacent nodes
        for (int next : adj[node])
        {
            indegree[next]--;
            // If indegree becomes 0, add it to the queue
            if (indegree[next] == 0)
                q.push(next);
        }
    }
    // If not all nodes were processed, a cycle exists
    return processed != n;
}

// Your code here
void Solve()
{
    int n = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 1}};
    if (hasCycle(n, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}