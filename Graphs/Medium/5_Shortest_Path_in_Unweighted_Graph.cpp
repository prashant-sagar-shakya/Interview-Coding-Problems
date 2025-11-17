#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();

    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1;

    vector<pair<int, int>> dirs = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    queue<vector<int>> q;
    q.push({0, 0, 1});
    grid[0][0] = 1;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int r = curr[0], c = curr[1], dist = curr[2];
        if (r == n - 1 && c == n - 1)
            return dist;
        for (auto &d : dirs)
        {
            int nr = r + d.first;
            int nc = c + d.second;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0)
            {
                grid[nr][nc] = 1;
                q.push({nr, nc, dist + 1});
            }
        }
    }
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