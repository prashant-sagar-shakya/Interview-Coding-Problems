#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Approach 1: Reverse letters in each word (word order stays the same)
void ReverseEachWord(string &s)
{
    int start = 0;
    for (int end = 0; end <= s.size(); end++)
    {
        if (end == s.size() || s[end] == ' ')
        {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
    }
}

// Approach 2: Reverse order of words (words themselves stay intact)
void ReverseWordOrder(string &s)
{
    stringstream ss(s);
    vector<string> words;
    string word;

    while (ss >> word)
        words.push_back(word);

    s.clear();
    for (int i = words.size() - 1; i >= 0; i--)
    {
        s += words[i];
        if (i != 0)
            s += " ";
    }
}

// Your code here
void Solve()
{
    string s;
    getline(cin, s);
    string s1 = s, s2 = s;

    // Reverse letters in each word
    ReverseEachWord(s1);
    cout << s1 << endl;
    // Reverse order of words
    ReverseWordOrder(s2);
    cout << s2;
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}