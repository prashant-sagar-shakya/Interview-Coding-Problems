#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<string> valid;

void generate(string &s, int open, int close)
{
    // If no opening and closing brackets exist anymore
    if (open == 0 && close == 0)
    {
        valid.push_back(s);
        return;
    }

    // If Openening Bracket Exists
    if (open > 0)
    {
        s.push_back('(');
        generate(s, open - 1, close);
        s.pop_back();
    }
    // If Closing Brackets Exists
    if (close > 0)
    {
        // If count of opening brackets used in string is more than count of closing brackets
        if (open < close)
        {
            s.push_back(')');
            generate(s, open, close - 1);
            s.pop_back();
        }
    }
}

vector<string> GenerateParantheses(int n)
{
    string s;
    generate(s, n, n);
    return valid;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<string> result = GenerateParantheses(n);

    for (string &s : result)
        cout << s << endl;
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}