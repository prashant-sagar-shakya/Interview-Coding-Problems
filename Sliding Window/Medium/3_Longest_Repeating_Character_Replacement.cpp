#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// You are given a string **s** and an integer **k**. You can change any character in the string to any other uppercase English letter, but you can perform this operation at most **k** times. Your task is to find and return the length of the longest possible substring that can consist of the same character after performing up to **k** such operations.

int characterReplacement(string s, int k)
{
    // Step 1: Create a frequency array to store count of each uppercase letter (A–Z)
    vector<int> charF(26, 0);
    int n = s.size();  // Total length of string
    int maxSubStr = 0; // Variable to store length of the longest valid substring
    // Step 2: Edge case — if the entire string can be converted within k operations
    if (n <= k)
        return n;
    int left = 0, right = 0; // Sliding window boundaries
    int maxF = 0;            // Maximum frequency of any character inside the window
    // Step 3: Traverse through the string using right pointer
    while (right < n)
    {
        // Increase frequency of current character
        charF[s[right] - 'A']++;
        // Update maxF (the most frequent character count in the current window)
        maxF = max(maxF, charF[s[right] - 'A']);
        // Expand the window by moving right pointer
        right++;
        // Step 4: Check if the current window is invalid
        // (Window length - most frequent char count) = number of replacements needed
        if ((right - left - maxF) > k)
        {
            // Too many replacements → shrink window from left
            charF[s[left] - 'A']--; // Remove leftmost char from frequency count
            left++;                 // Move left pointer to the right
        }
        // Step 5: Update maximum substring length
        maxSubStr = max(maxSubStr, right - left);
    }
    // Step 6: Return the longest valid substring length
    return maxSubStr;
}

// Your code here
void Solve()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << characterReplacement(s, k);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}