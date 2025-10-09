#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

bool isPalindrome(vector<int> &arr)
{
    // Two Pointer Approach
    int i = 0, j = arr.size() - 1;
    while (i <= j)
    {
        if (arr[i++] == arr[j--])
            continue;
        else
            return false;
    }
    return true;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    cout << boolalpha << isPalindrome(arr);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}