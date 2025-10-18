#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<int> Product(vector<int> &arr)
{
    // Intution of Prefix and Postfix
    int n = arr.size();
    vector<int> Ans(n, 1);

    int prefix = 1; // Product of elements on left side
    for (int i = 0; i < n; i++)
    {
        Ans[i] *= prefix; // Multiply with left product
        prefix *= arr[i]; // Update prefix
    }

    int postfix = 1; // Product of elements on right side
    for (int i = n - 1; i >= 0; i--)
    {
        Ans[i] *= postfix; // Multiply with right product
        postfix *= arr[i]; // Update postfix
    }

    return Ans; // Final answer array
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    vector<int> Result = Product(arr);
    for (int &i : arr)
        cout << i << " ";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}