#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Your code here
void Solve()
{
    string s;
    cin >> s;
    // using map to find frequency
    map<char, int> mpp;
    for (int i = 0; i < s.length(); i++)
        mpp[s[i]]++;
    for (auto &i : mpp)
        cout << i.first << " : " << i.second << endl;
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}