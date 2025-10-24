#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int mySqrt(int x)
{
    // Handle small numbers directly
    if (x < 2)
        return x;      // sqrt(0)=0, sqrt(1)=1
    int left = 1;      // Start from 1
    int right = x / 2; // No square root greater than x/2 for x > 1

    // Binary search for the square root
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Calculate mid safely
        long long square = 1LL * mid * mid;  // Use long long to prevent overflow

        if (square == x)
            return mid; // Exact square root found
        else if (square < x)
            left = mid + 1; // Move right to find larger square
        else
            right = mid - 1; // Move left to find smaller square
    }

    return right; // When loop ends, right will be the integer part of sqrt(x)
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    cout << mySqrt(n);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}