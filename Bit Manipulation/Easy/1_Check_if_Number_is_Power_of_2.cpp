#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Your code here
void Solve()
{
    int n;
    cin >> n;
    // If a number is power of 2 then it has only one set bit
    cout << (__builtin_popcount(n) == 1 ? "Yes" : "No"); // __builtin_popcount(n) is the built-in function to count number of setbits in a given number n

    // Second Way
    /*
    if(n&(n-1)==0) // Removes the last setbit rightmost
        cout<<"Yes";
    else
        cout<<"No";
    */
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}