#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int countSetBits(int n)
{
    n++;           // Increment n as we are counting set bits from 1 to n, ignoring 0 as all bits are unset
    int count = 0; // Initialize count of set bits
    for (int x = 2; x / 2 < n; x = x * 2)
    {
        int quotient = n / x;      // Total count of complete pairs of 0s and 1s
        count += quotient * x / 2; // Count of 1s in the current bit position
        int remainder = n % x;     // Remaining elements after complete pairs
        if (remainder > x / 2)
            count += remainder - x / 2; // Add extra 1s not in complete pairs
    }
    return count; // Return total count of set bits from 1 to n
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    cout << countSetBits(n);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}