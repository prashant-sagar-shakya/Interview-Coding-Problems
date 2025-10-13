#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

bool Palindromic_Array(vector<int> &arr)
{
    int l = 0, r = arr.size() - 1;
    while (l <= r)
    {
        if (arr[l] == arr[r])
        {
            l++;
            r--;
        }
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
    cout << boolalpha << Palindromic_Array(arr);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}