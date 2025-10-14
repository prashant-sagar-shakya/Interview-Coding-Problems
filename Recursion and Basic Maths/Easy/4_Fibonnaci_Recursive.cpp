#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int Fibonnaci_Recursive(int n)
{
    if (n == 1)
        return 0;
    if(n==2)
        return 1;
    return Fibonnaci_Recursive(n - 1) + Fibonnaci_Recursive(n - 2);
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    cout << Fibonnaci_Recursive(n);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}