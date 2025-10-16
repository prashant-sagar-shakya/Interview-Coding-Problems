//  You are given an integer array cost where cost[i] is the cost of ith step on a staircase.Once you pay the cost, you can either climb one or two steps. You can either start from the step with index 0, or the step with index 1. Return the minimum cost to reach the top of the floor.

#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<int> dp; // Bottom-Up Tabulation DP Array
// Function to find the minimum cost to climb 'n' stairs
int minCost(vector<int> &cost, int n)
{
    // If we have already computed the answer for 'n', return it (Memoization)
    if (dp[n] != -1) // 'dp' should be defined globally or passed as reference
        return dp[n];

    // Base case: If there are 0 or 1 stairs, no cost is needed
    if (n <= 1)
        return dp[n] = 0;

    // Base case: If there are 2 stairs, the minimum cost is the smaller of the first two steps
    if (n == 2)
        return dp[n] = min(cost[0], cost[1]);

    // Recurrence:
    // Minimum cost to reach the nth stair =
    // Minimum of:
    //   1. Cost to reach (n-1)th stair + cost of stepping on (n-1)th stair
    //   2. Cost to reach (n-2)th stair + cost of stepping on (n-2)th stair
    return dp[n] = min(
               minCost(cost, n - 1) + cost[n - 1],
               minCost(cost, n - 2) + cost[n - 2]);
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    dp.resize(n + 1);               // Resizing the tabulation array of size n + 1
    fill(dp.begin(), dp.end(), -1); // Initializing all the elements of tabulation array with -1
    return minCost(cost, n);
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> cost(n);
    for (auto &i : cost)
        cin >> i;
    cout << minCostClimbingStairs(cost);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}