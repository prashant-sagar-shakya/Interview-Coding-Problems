#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long

ll Factorial_Recursive(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * Factorial_Recursive(n - 1);
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