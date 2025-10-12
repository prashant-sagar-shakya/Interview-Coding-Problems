#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void Reverse(string &s, int l, int r)
{
    while (l <= r)
        swap(s[l++], s[r--]);
}

void ReverseWC(string &s)
{
    int i = 0;
    // Reverse the whole string
    Reverse(s, 0, s.length() - 1);
    // Reverse each word
    for (int j = 0; j < s.length(); j++)
    {
        if (s[j] == ' ' || j == s.length() - 1)
        {
            int end = (s[j] == ' ') ? (j - 1) : j;
            Reverse(s, i, end);
            i = j + 1;
        }
    }
}

// Your code here
void Solve()
{
    string s;
    getline(cin, s);
    ReverseWC(s);
    cout << s;
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}