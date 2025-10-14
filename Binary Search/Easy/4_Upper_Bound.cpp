#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int Upper_Bound(vector<int> arr, int target)
{
    int l = 0, r = arr.size() - 1, res = arr.size();
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] > target)
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
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
    cout << Upper_Bound(arr, target);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}