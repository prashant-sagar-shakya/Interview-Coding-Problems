#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int mod = 1e9 + 7; // Define a large prime number (used to prevent overflow in modular arithmetic)

// Function to compute (a^b) % mod using fast exponentiation (binary exponentiation)
long long binExp(long long a, long long b)
{
    long long result = 1; // Initialize result as 1 (anything raised to power 0 is 1)
    a = a % mod;          // Bring 'a' within modulo range to handle large numbers
    while (b > 0)         // Loop until the power becomes 0
    {
        // If current power (b) is odd, multiply result by current base 'a'
        if (b % 2 == 1)
            result = (result * a) % mod;
        // Square the base (a = a^2)
        a = (a * a) % mod;
        // move to next bit in binary representation of b
        b >>= 1;
    }
    return result; // Final result = (a^b) % mod
}

// Recursive Implementation of binary exponentation
/*
long long binExp(long long a, long long b)
{
    // Base case: anything to the power 0 is 1
    if (b == 0)
        return 1;
    // Base case: 0 raised to any positive power is 0
    if (a == 0)
        return 0;
    // Recursively compute half = a^(b/2) using right shift (b >> 1 == b/2)
    long long half = binExp(a, b >> 1);
    // Square the half result under modulo
    long long result = (half * half) % mod;
    // If b is odd (check last bit using b & 1)
    if (b & 1)
        result = (result * (a % mod)) % mod;
    // Return final result modulo mod
    return result;
}
*/

// Your code here
void Solve()
{
    int a, b;
    cin >> a >> b;
    cout << binExp(a, b);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}