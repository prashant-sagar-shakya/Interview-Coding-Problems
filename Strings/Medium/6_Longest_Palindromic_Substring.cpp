#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Manachar's Algorithm is the most efficient approach for this problem takes O(n) time

// Expand around the given center (i, j) and return length of palindrome => O(n^2)
int ExpandFromCenter(const string &s, int i, int j)
{
    // Expand while characters are equal and within bounds
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        i--; // move left pointer outward
        j++; // move right pointer outward
    }
    // Length of palindrome is right - left - 1 (because i & j have moved one step extra)
    return j - i - 1;
}

string LongestPalindrome(const string &s)
{
    int start = 0, end = 0; // To track the start and end of the longest palindrome

    for (int i = 0; i < s.length(); i++)
    {
        // Check palindrome of odd length centered at i
        int len1 = ExpandFromCenter(s, i, i);
        // Check palindrome of even length centered between i and i+1
        int len2 = ExpandFromCenter(s, i, i + 1);
        // Maximum length palindrome at this center
        int len = max(len1, len2);
        // Update start and end if this palindrome is longer than previous
        if (len > end - start + 1)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    // Extract and return the longest palindromic substring
    return s.substr(start, end - start + 1);
}

// Your code here
void Solve()
{
    string s;
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}