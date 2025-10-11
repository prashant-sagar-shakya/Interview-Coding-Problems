#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

string RemoveVowels(string s)
{
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        switch (tolower(s[i]))
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            continue;
        default:
            result += s[i];
        }
    }
    return result;
}

string RemoveSpaces(string s)
{
    string x = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            continue;
        x += s[i];
    }
    return x;
}

// Your code here
void Solve()
{
    string s;
    getline(cin, s);
    string res1 = RemoveVowels(s);
    string res2 = RemoveSpaces(s);
    cout << res1 << endl;
    cout << res2;
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}