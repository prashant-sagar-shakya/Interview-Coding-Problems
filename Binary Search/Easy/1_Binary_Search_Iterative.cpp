#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int Binary_Search_Iterative(vector<int> arr, int target)
{
    int l = 0, r = arr.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
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
    cout << Binary_Search_Iterative(arr, target);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}