#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long

ll Factorial_Iterative(int n)
{
    ll fact = 1;
    if (n == 1 || n == 0)
        return fact;
    for (int i = 2; i <= n; i++)
        fact *= i;

    return fact;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    cout << Factorial_Iterative(n);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}