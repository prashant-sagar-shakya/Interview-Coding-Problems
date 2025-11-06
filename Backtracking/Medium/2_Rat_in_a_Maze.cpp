#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// A rat is placed at the top - left corner(0, 0) of an n x n maze filled with 0s and 1s, where 1 means an open path and 0 means a blocked cell.The rat needs to reach the bottom - right corner(n - 1, n - 1) by moving only up(U), down(D), left(L), or right(R).It cannot move outside the maze or revisit a cell in the same path.Find all possible paths the rat can take to reach the destination, and return them in lexicographical order.If no path exists, return an empty list.

// Recursive function to explore all valid paths from (x, y) to destination
void explorePaths(int x, int y, int n, vector<vector<int>> &maze, string &path, set<string> &ans, vector<vector<bool>> &vis)
{

    // Base condition: reached the destination cell (bottom-right corner)
    if (x == n - 1 && y == n - 1)
    {
        ans.insert(path); // store the current path
        return;
    }

    // Arrays to represent four possible movements: Up, Down, Left, Right
    int delx[4] = {-1, 1, 0, 0};
    int dely[4] = {0, 0, -1, 1};
    char dir[4] = {'U', 'D', 'L', 'R'}; // corresponding direction characters

    // Try all four directions one by one
    for (int i = 0; i < 4; i++)
    {
        int nx = x + delx[i]; // next x-coordinate
        int ny = y + dely[i]; // next y-coordinate

        // Check if the next cell is valid, open, and not yet visited
        if (nx >= 0 && ny >= 0 && nx < n && ny < n && maze[nx][ny] && !vis[nx][ny])
        {
            // Choose: mark this cell and move in the chosen direction
            path.push_back(dir[i]);
            vis[nx][ny] = true;

            // Explore further from the new cell
            explorePaths(nx, ny, n, maze, path, ans, vis);

            // Backtrack: unmark this cell and remove the last direction
            vis[nx][ny] = false;
            path.pop_back();
        }
    }
}

// Function to find all paths for the rat to move from start to destination
vector<string> ratInMaze(vector<vector<int>> &maze)
{
    int n = maze.size();
    set<string> res;                                     // stores unique paths in sorted order
    vector<vector<bool>> vis(n, vector<bool>(n, false)); // visited matrix
    string path = "";

    // Start only if the starting cell is open
    if (maze[0][0] == 1)
    {
        vis[0][0] = true;
        explorePaths(0, 0, n, maze, path, res, vis);
    }

    // Convert the set to a vector before returning
    vector<string> ans(res.begin(), res.end());
    return ans;
}

// Your code here
void Solve()
{
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}