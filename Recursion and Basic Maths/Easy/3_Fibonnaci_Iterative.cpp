#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int Fibonnaci_Iterative(int n){
    int n1 = 0, n2 = 1, nt = 0;
    if(n==1)
        return 0;
    for (int i = 2; i <= n; i++){
        n1 = n2;
        n2 = nt;
        nt = n1 + n2;
    }
    return nt;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    cout << Fibonnaci_Iterative(n);
}

// Driver code
int main() {
    fastio();
    Solve();
    return 0;
}