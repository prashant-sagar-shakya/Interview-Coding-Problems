#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Your code here
void Solve()
{
    // Number of vertices and edges
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjMat(n + 1, vector<int>(n + 1, 0));
    // Enter edges (u v)
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1; // for undirected graph
    }
    // Printint the Matrix
    for (auto arr : adjMat)
    {
        for (auto ele : arr)
            cout << ele << " ";
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