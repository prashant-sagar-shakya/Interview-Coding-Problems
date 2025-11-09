#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();                                   // number of items
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)); // dp[i][w] stores max value using first i items and capacity w

    for (int i = 1; i <= n; i++)
    { // iterate through all items
        for (int w = 1; w <= W; w++)
        { // iterate through all capacities
            if (wt[i - 1] <= w)
            {                                                     // if current item fits in the curren capacity
                int take = val[i - 1] + dp[i - 1][w - wt[i - 1]]; // include current item
                int notTake = dp[i - 1][w];                       // exclude current item
                dp[i][w] = max(take, notTake);                    // take the better of the two choices
            }
            else
                dp[i][w] = dp[i - 1][w]; // cannot include current item, so inherit previous value
        }
    }
    return dp[n][W]; // the bottom-right cell gives the maximum obtainable value
}

// Your code here
void Solve()
{
    int W = 50;
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    cout << "Maximum value in Knapsack: " << knapsack(W, val, wt);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}