#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

bool isArmstrong(int n)
{
    int digit_cnt = floor(log10(n)) + 1;
    int sum = 0;
    int x = n;
    while (x != 0)
    {
        int last = x % 10;
        x /= 10;
        sum += pow(last, digit_cnt);
    }
    if (sum == n)
        return true;
    else
        return false;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    cout << boolalpha << isArmstrong(n);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}