#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

bool Palindromic_String(string &s)
{
    int l = 0, r = s.length() - 1;
    while (l <= r)
    {
        if (s[l] == s[r])
        {
            l++;
            r--;
        }
        else
            return false;
    }
    return true;
}

// Your code here
void Solve()
{
    string s;
    cin >> s;
    cout << boolalpha << Palindromic_String(s);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}