#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int LongestSubstring(string &s)
{
    vector<int> v(128, -1); // This vector stores the last index at which each character appeared
    int res = 0;            // Stores the maximum length of substring found
    int ptr = 0;            // Points to the start of current substring window

    // Iterate through the string s using index i
    for (int i = 0; i < s.length(); i++)
    {
        // If s[i] has appeared within the current valid substring v[s[i]] >= ptr then update ptr = v[s[i]] + 1 to move the previous occurence
        if (v[s[i]] >= ptr)
            ptr = v[s[i]] + 1;

        // Update v[s[i]] = i to store the latest index of s[i]
        v[s[i]] = i;

        // compute the length of current valid substring
        res = max(res, i - ptr + 1);
    }
    return res;
}

// Your code here
void Solve()
{
    string s;
    cin >> s;
    cout << LongestSubstring(s);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}