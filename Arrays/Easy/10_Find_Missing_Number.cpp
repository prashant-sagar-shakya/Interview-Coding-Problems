#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int MissingNumber(vector<int> &arr)
{
    int xor_all = 0, xor_arr = 0;

    for (int i = 0; i <= arr.size(); i++)
        xor_all = xor_all ^ i;
    for (int i = 0; i < arr.size(); i++)
        xor_arr = xor_arr ^ arr[i];

    // Missing Number = xor_all ^ xor_arr
    return xor_all ^ xor_arr;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    cout << MissingNumber(arr);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}