#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// This will store all possible valid board configurations
vector<vector<string>> res;

// Recursive backtracking function to place queens safely on the board
void placeQueens(int n, int row, vector<int> &queens,
                 vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2)
{
    // Base case: if all queens are placed successfully
    if (row == n)
    {
        // Construct the board representation from 'queens' array
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; i++)
            board[i][queens[i]] = 'Q'; // place queen at (i, queens[i])

        // Add the valid board configuration to the result
        res.push_back(board);
        return;
    }

    // Try placing the queen in each column for the current row
    for (int col = 0; col < n; col++)
    {
        // Check if the column or diagonals are already under attack
        if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
            continue; // skip unsafe positions
        // Choose: place queen at (row, col)
        queens[row] = col;
        cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;
        // Recurse to the next row
        placeQueens(n, row + 1, queens, cols, diag1, diag2);
        // Backtrack: remove queen and reset safety markers
        cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
    }
}

// Function to initialize data structures and start recursion
vector<vector<string>> solveNQueens(int n)
{
    vector<int> queens(n, 0);             // queens[i] = column index where queen is placed in row i
    vector<bool> cols(n, false);          // marks used columns
    vector<bool> diag1(2 * n - 1, false); // marks used main diagonals (row + col)
    vector<bool> diag2(2 * n - 1, false); // marks used anti-diagonals (row - col + n - 1)

    // Start recursive backtracking from row 0
    placeQueens(n, 0, queens, cols, diag1, diag2);

    return res; // return all valid configurations
}

// Your code here
void Solve()
{
    int n; // No. of Queens
    cin >> n;
    solveNQueens(n);
    int limit = res.size();

    for (auto arr : res)
    {
        for (string s : arr)
            cout << s << "\n";
        if (limit != 1)
        {
            cout << "----------------------------------Another Solution-------------------------------------------\n";
            limit--;
        }
    }
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}