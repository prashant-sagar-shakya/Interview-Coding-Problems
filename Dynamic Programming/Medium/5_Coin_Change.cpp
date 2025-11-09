#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int minCoinsHelper(vector<int> &coins, int rem, vector<int> &memo)
{
    if (rem < 0)
        return -1; // if remaining amount is negative, no valid solution
    if (rem == 0)
        return 0; // if remaining amount is zero, no coins needed
    if (memo[rem] != -2)
        return memo[rem]; // if already computed, return cached value

    int min_count = INT_MAX; // store minimum coins required among all possibilities
    for (int coin : coins)
    {                                                      // iterate over each coin denomination
        int res = minCoinsHelper(coins, rem - coin, memo); // recursively solve for remaining amount
        if (res >= 0 && res < min_count)
            min_count = 1 + res; // update minimum if valid and smaller
    }
    memo[rem] = (min_count == INT_MAX) ? -1 : min_count; // store -1 if no valid way, else min count
    return memo[rem];                                    // return computed result for current remaining amount
}

int coinChange(vector<int> &coins, int amount)
{
    vector<int> memo(amount + 1, -2);           // memo array initialized with -2 (uncomputed state)
    return minCoinsHelper(coins, amount, memo); // start recursion for the given amount
}

// Your code here
void Solve()
{
    int n;
    vector<int> coins(n);
    for (int &i : coins)
        cin >> i;
    int amt;
    cin >> amt;
    cout << coinChange(coins, amt);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}