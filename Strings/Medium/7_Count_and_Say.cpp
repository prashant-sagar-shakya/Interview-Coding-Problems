#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// The count-and-say sequence is a fascinating pattern of digit strings built recursively.It starts with countAndSay(1) = "1", and each following term describes the previous one using "run length encoding" —> a simple compression technique where consecutive identical digits are replaced by their count followed by the digit itself.For example, the string "3322251" becomes "23321511" because "33" → "23", "222" → "32", "5" → "15", and "1" → "11".Given a positive integer n, the goal is to generate the nth term of this sequence.

// Function to perform Run-Length Encoding (RLE)
string RLE(const string &s)
{
    string res = "";
    int cnt = 1;

    // Traverse the string and count consecutive identical digits
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1]) // Same digit → increase count
            cnt++;
        else // Append "count + digit" for previous run
        {
            res += to_string(cnt) + s[i - 1];
            cnt = 1; // Reset counter for new digit
        }
    }
    // Handle the last group
    res += to_string(cnt) + s.back();
    return res;
}

string countAndSay(int n)
{
    string res = "1"; // Base case: countAndSay(1) = "1"
    // Iteratively build the sequence up to n
    for (int i = 1; i < n; i++)
        res = RLE(res);
    return res;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    cout << countAndSay(n);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}