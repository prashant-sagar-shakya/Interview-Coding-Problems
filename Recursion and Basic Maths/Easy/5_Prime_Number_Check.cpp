#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    else if (n == 2 || n == 3)
        return true;
    else if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    cout << boolalpha << isPrime(n);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}