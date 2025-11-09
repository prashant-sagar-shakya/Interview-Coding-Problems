#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int XOR_all_Subarrays(vector<int> &arr)
{
    int n = arr.size();            // store array size
    int ans = arr[0];              // initialize XOR result with first element
    if (n % 2 == 0)                // if array has even number of elements
        return 0;                  // overall XOR of all subarrays will be 0
    for (int i = 2; i < n; i += 2) // iterate over even indices only
        ans ^= arr[i];             // XOR all elements at even positions (0-based)
    return ans;                    // return final XOR value
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    cout << XOR_all_Subarrays(arr);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}