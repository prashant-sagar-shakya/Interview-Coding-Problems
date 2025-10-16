// Find the distinct number of ways to climb a staircase of n steps if you take 1 or 2 steps at a time

#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int Climbing_Stairs(int n)
{
    // step[n] = step[n - 1] + step[n - 2] -> Fibonnaci Pattern 1 - Based
    if (n == 1)
        return 1;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    cout << Climbing_Stairs(n);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}