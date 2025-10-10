#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void Reverse(string &s)
{
    int l = 0, r = s.length() - 1;
    while (l <= r)
    {
        swap(s[l++], s[r--]);
    }
}

bool Palindrome(string &s)
{
    string check = s;
    Reverse(s);
    return (check == s);
}

// Your code here
void Solve()
{
    string s;
    cin >> s;
    cout << boolalpha << Palindrome(s);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}