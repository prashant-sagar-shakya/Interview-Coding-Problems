#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void Capitalize(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (i == 0 || i == s.length() - 1)
            s[i] = toupper(s[i]);
        else if (s[i] == ' ')
        {
            s[i + 1] = toupper(s[i + 1]);
            s[i - 1] = toupper(s[i - 1]);
        }
    }
}

// Your code here
void Solve()
{
    string s;
    getline(cin, s);
    Capitalize(s);
    cout << s;
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}