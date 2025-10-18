#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

bool ValidAnagram(string &s1, string &s2)
{
    if (s1.length() != s2.length())
        return false;

    // Creating a frequency array to store freuency of lowercase a - z
    vector<int> freq(26, 0);

    // Count characters from s1
    for (char ch : s1)
        freq[ch - 'a']++;
    // Subtract counts using characters from s2
    for (char ch : s2)
        freq[ch - 'a']--;
    // Check if all counts are 0 or not
    for (int i : freq)
    {
        if (i != 0) // Mismatch found
            return false;
    }
    return true;
}

// Your code here
void Solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << ValidAnagram(s1, s2);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}