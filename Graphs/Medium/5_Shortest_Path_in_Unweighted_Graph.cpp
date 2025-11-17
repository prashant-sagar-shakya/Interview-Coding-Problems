#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size(); // size of grid (n x n)
    // If starting cell OR ending cell is blocked, no path possible
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1;
    // All 8 possible movement directions (including diagonals)
    vector<pair<int, int>> dirs = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    // BFS queue → each element stores (row, col, distance)
    queue<vector<int>> q;
    // Start from (0,0) with path length = 1
    q.push({0, 0, 1});
    // Mark starting cell as visited
    grid[0][0] = 1;
    // Standard BFS loop
    while (!q.empty())
    {
        // Get current BFS state
        auto curr = q.front();
        q.pop();
        int r = curr[0];    // current row
        int c = curr[1];    // current column
        int dist = curr[2]; // current path length
        // If we reached bottom-right, return distance (shortest path)
        if (r == n - 1 && c == n - 1)
            return dist;
        // Explore all 8 neighbors
        for (auto &d : dirs)
        {
            int nr = r + d.first;  // next row
            int nc = c + d.second; // next column
            // Check bounds and if the cell is open (0)
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0)
            {
                grid[nr][nc] = 1; // mark next cell visited
                // Push next state with increased path length
                q.push({nr, nc, dist + 1});
            }
        }
    }
    // If BFS ends without reaching destination → no path exists
    return -1;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    cout << shortestPathBinaryMatrix(grid) << "\n";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}