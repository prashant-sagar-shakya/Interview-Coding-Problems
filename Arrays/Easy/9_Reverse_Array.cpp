#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void Reverse(vector<int> &arr)
{
    // Using Two Pointer Approach
    int i = 0, j = arr.size() - 1;
    while (i <= j)
        swap(arr[i++], arr[j--]);
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    Reverse(arr);
    // Printing The Array
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