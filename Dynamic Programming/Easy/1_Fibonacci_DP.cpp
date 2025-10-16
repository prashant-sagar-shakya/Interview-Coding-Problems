#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<long long> Memo(10000001, -1); // Use -1 to indicate uncomputed

// Top-Down (Memoization) Fibonacci
long long Memo_Fibonnaci(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (Memo[n] == -1) // if result is undefined
        Memo[n] = Memo_Fibonnaci(n - 1) + Memo_Fibonnaci(n - 2);
    return Memo[n];
}

// Bottom-Up (Tabulation) Fibonnaci
long long Tabular_Fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    vector<long long> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

void Solve()
{
    int n;
    cin >> n;
    cout << Memo_Fibonnaci(n) << endl;
    // cout << Tabular_Fibonacci(n) << endl;
}

int main()
{
    fastio();
    Solve();
    return 0;
}
