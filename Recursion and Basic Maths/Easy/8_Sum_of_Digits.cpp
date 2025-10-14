#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int Sum_of_Digits(int n)
{
    int sum = 0;
    while (n != 0)
    {
        int last = n % 10;
        n /= 10;
        sum += last;
    }
    return sum;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    cout << Sum_of_Digits(n);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}