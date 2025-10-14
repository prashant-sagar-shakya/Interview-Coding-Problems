#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long

ll Factorial_Recursive(int n)
{
    int fact = 1;
    if (n == 0 || n == 1)
        return fact;
    return fact * Factorial_Recursive(n - 1);
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    cout << Factorial_Recursive(n);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}