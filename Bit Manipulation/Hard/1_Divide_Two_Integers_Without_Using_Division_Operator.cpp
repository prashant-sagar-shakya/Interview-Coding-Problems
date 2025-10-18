#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int divide(int dividend, int divisor)
{
    // Step 1: If dividend and divisor are equal, result is 1
    if (dividend == divisor)
        return 1;
    // Step 2: Determine the sign of the result
    // Result is positive if both have the same sign, negative otherwise
    bool isPositive = (dividend < 0 == divisor < 0);
    // Step 3: Work with absolute values to simplify calculations
    unsigned int a = abs(dividend);
    unsigned int b = abs(divisor);
    unsigned int ans = 0; // To store the quotient

    // Step 4: Subtract multiples of divisor from dividend
    while (a >= b)
    {
        short q = 0; // Power of 2 multiplier
        // Find the largest power of 2 such that (b * 2^q) <= a
        while (a > (b << (q + 1)))
            q++;
        // Add the found multiple to the answer
        ans += (1 << q);
        // Subtract the corresponding multiple from a
        a = a - (b << q);
    }

    // Step 5: Handle overflow case
    if (ans == (1 << 31) && isPositive)
        return INT_MAX;
    // Step 6: Apply the sign to the answer
    return isPositive ? ans : -ans;
}

// Your code here
void Solve()
{
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide(dividend, divisor);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}