#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int Binary_Search_Recursive(vector<int> arr, int l, int r, int target)
{
    if (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            return Binary_Search_Recursive(arr, l, mid - 1, target);
        else if (arr[mid] < target)
            return Binary_Search_Recursive(arr, mid + 1, r, target);
    }
    return -1;
}
// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    int target;
    cin >> target;
    cout << Binary_Search_Recursive(arr, 0, n - 1, target);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}