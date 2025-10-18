#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#include <bits/stdc++.h>
using namespace std;

// Also known as KMP (Knuth-Morris-Pratt) String AMthing or Pattern Search Algo

// Function to build the LPS (Longest Prefix Suffix) array
void computeLPSArray(string &pattern, vector<int> &lps)
{
    int m = pattern.size();
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0;  // LPS[0] is always 0
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            // Characters match, extend current prefix-suffix
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) // Try previous longest prefix suffix
                len = lps[len - 1];
            else
            {
                // No match and no previous prefix, set LPS[i] = 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Pattern Search function
vector<int> KMPSearch(string &text, string &pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> lps(m, 0); // LPS array
    vector<int> result;    // Stores starting indices of matches

    // Step 1: Build the LPS array for the pattern
    computeLPSArray(pattern, lps);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    // Step 2: Traverse the text to find matches
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            // Full pattern matched
            result.push_back(i - j); // Store starting index of match
            j = lps[j - 1];          // Move pattern index using LPS
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0) // Use LPS to avoid unnecessary comparisons
                j = lps[j - 1];
            else // No match, move text index forward
                i++;
        }
    }

    return result; // Return all starting indices where pattern occurs
}

// Your code here
void Solve()
{
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    // Call KMP search function
    vector<int> matches = KMPSearch(text, pattern);

    if (matches.empty())
        cout << -1; // No Match Found
    else
        for (int idx : matches)
            cout << idx << " ";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}