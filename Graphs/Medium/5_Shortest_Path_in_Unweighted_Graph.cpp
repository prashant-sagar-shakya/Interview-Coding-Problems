#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Classical Dijkstra's Algorithm for finding shortest paths from a single source
void dijkstra(int n, vector<vector<pair<int, int>>> &adj, int src)
{
    // Distance array initialized with infinity
    vector<int> dist(n, INT_MAX);
    // Min-heap (priority queue) to get the node with the smallest distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Distance to source is 0
    dist[src] = 0;
    pq.push({0, src});

    // Process the graph
    while (!pq.empty())
    {
        int d = pq.top().first;     // current shortest distance
        int node = pq.top().second; // current node
        pq.pop();
        // Skip if we already found a better path
        if (d > dist[node])
            continue;
        // Explore all adjacent nodes
        for (auto &edge : adj[node])
        {
            int next = edge.first;
            int weight = edge.second;
            // If a shorter path is found, update and push to the queue
            if (dist[node] + weight < dist[next])
            {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    // Print shortest distances from source
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; ++i)
    {
        if (dist[i] == INT_MAX)
            cout << "Node " << i << " : Unreachable\n";
        else
            cout << "Node " << i << " : " << dist[i] << "\n";
    }
}

// Your code here
void Solve()
{
    int n = 5; // number of nodes
    // Graph representation: adjacency list (node -> [(neighbor, weight)])
    vector<vector<pair<int, int>>> adj(n);
    // Sample undirected weighted graph
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    adj[0].push_back({2, 4});
    adj[2].push_back({0, 4});
    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});
    adj[1].push_back({3, 7});
    adj[3].push_back({1, 7});
    adj[2].push_back({4, 3});
    adj[4].push_back({2, 3});

    // Run Dijkstra from source node 0
    dijkstra(n, adj, 0);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}