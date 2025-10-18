#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

string minWindow(string &s, string &t)
{
    // Step 1: Handle edge cases where window search is not possible
    if (s.empty() || t.empty() || s.length() < t.length())
        return "";

    // Step 2: Frequency array to count required characters from string t
    vector<int> freq(128, 0); // Supports all ASCII characters

    int cnt = t.length();    // Number of characters we still need to match
    int left = 0, right = 0; // Sliding window pointers
    int res = INT_MAX;       // Length of the smallest valid window found
    int startIdx = 0;        // Starting index of the smallest window
    int n = s.length();      // Length of string s

    // Step 3: Initialize frequency array with string t
    for (char ch : t)
        freq[ch]++;
    // Step 4: Expand window using 'right' pointer
    while (right < n)
    {
        // If current char is still needed (freq > 0), decrement 'cnt'
        if (freq[s[right++]]-- > 0)
            cnt--;
        // Step 5: When all required chars are found (cnt == 0)
        while (cnt == 0)
        {
            // Update smallest window size if current one is smaller
            if (right - left < res)
            {
                startIdx = left;
                res = right - left;
            }
            // Try to shrink the window from left side
            // If a needed char is removed (freq == 0 before increment), increase 'cnt'
            if (freq[s[left++]]++ == 0)
            {
                cnt++;
            }
        }
    }
    // Step 6: Return the smallest window substring if found, else empty string
    return res == INT_MAX ? "" : s.substr(startIdx, res);
}

// Your code here
void Solve()
{
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}