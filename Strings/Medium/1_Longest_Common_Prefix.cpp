#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Function to find the longest common prefix among an array of strings
string longestCommonPrefix(vector<string> &strs)
{
    // Edge case: if input list is empty
    if (strs.empty())
        return "";
    // Start by assuming the first string is the common prefix
    string prefix = strs[0];

    // Compare prefix with each string in the array
    for (int i = 1; i < strs.size(); i++)
    {
        // While the current string does not start with the current prefix, keep shortening the prefix from the end
        while (strs[i].find(prefix) != 0)
        {
            // Remove the last character
            prefix = prefix.substr(0, prefix.size() - 1);
            // If prefix becomes empty, there’s no common prefix
            if (prefix.empty())
                return "";
        }
    }
    return prefix;
}

// Your code here
void Solve()
{
    int n; // no. of strings
    cin >> n;
    vector<string> strs(n);
    for (string &s : strs)
        cin >> s;
    string res = longestCommonPrefix(strs);
    cout << res;
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}