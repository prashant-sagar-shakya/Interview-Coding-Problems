#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// You are given an array `coins` of different coin values and an integer `amount`. Using a greedy approach, pick the largest coin possible at each step to make up the amount. Return the minimum number of coins needed, or `-1` if it’s not possible to form the amount.

int coinChange(vector<int> &coins, int amount)
{
    sort(coins.rbegin(), coins.rend()); // sort in descending order
    int count = 0;

    for (int c : coins)
    {
        if (amount >= c)
        {
            count += amount / c; // take as many of this coin as possible
            amount = amount % c; // reduce remaining amount
        }
    }

    if (amount != 0)
        return -1; // if cannot form exact amount
    return count;
}

// Your code here
void Solve()
{
    vector<int> coins = {1, 2, 5, 10}; // or {1, 5, 10, 25, 50, 100} then only greedy solution works
    // i.e, for only Inidan Currency and US currency coin denominations the Greedy approach will work fine, otherwise for DP is required as a global Solution
    int amount;
    cin >> amount;
    cout << coinChange(coins, amount);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}