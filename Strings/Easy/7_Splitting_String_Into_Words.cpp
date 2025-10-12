#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<string> Split(string &s)
{
    vector<string> result;
    int i = 0;
    for (int j = 0; j < s.length(); j++)
    {
        if (s[j] == ' ' || j == s.length() - 1)
        {
            int len = (s[j] == ' ') ? (j - i) : (j - i + 1);
            if (len > 0)
                result.push_back(s.substr(i, len));
            i = j + 1;
        }
    }
    return result;
}

// Your code here
void Solve()
{
    string s;
    getline(cin, s);
    vector<string> result = Split(s);
    for (string &i : result)
        cout << i << ", ";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}