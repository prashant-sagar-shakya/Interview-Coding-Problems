#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int Last_Occurrence(vector<int> &arr, int target)
{
    int l = 0, r = arr.size() - 1, res = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
        {
            res = mid;
            l = mid + 1;
        }
        else if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
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
    cout << Last_Occurrence(arr, target);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}