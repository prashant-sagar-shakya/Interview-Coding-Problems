#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int longestCommonSubsequence(string text1, string text2)
{
    vector<int> dp(text1.length(), 0); // stores length of longest subsequence ending at each index of text1
    int longest = 0;                   // tracks overall maximum length found so far
    for (char c : text2)
    {                      // iterate through each character of text2
        int curLength = 0; // stores length of the best subsequence till current point in text1
        for (int i = 0; i < dp.size(); i++)
        { // traverse through text1
            if (curLength < dp[i])
                curLength = dp[i]; // update current best subsequence length seen so far
            else if (c == text1[i])
            {
                dp[i] = curLength + 1;         // extend current subsequence if characters match
                longest = max(longest, dp[i]); // update global maximum length
            }
        }
    }
    return longest; // return the length of longest common subsequence
}

// Your code here
void Solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << longestCommonSubsequence(s1, s2);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}