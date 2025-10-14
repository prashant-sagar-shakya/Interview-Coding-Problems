#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Your code here
void Solve()
{
    int n;
    cin >> n;
    cout << floor(log10(n)) + 1;
}

// Driver code
int main() {
    fastio();
    Solve();
    return 0;
}