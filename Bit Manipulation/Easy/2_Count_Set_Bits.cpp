#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int countSetBits(int n)
{
    // Brian Kernighan’s Algorithm
    int count = 0;
    while (n)
    {
        n = n & (n - 1); // remove the rightmost set bit
        count++;
    }
    return count;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    // Using Brian Kernighan’s Algorithm
    cout << countSetBits(n);

    // Using built-in function __builtin_popcount(n);
    // cout << __builtin_popcount(n);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}