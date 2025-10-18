#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int Maximum_Subarray_Sum(vector<int> &arr)
{
    int curr = 0, Max = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        curr += arr[i];
        if (Max < curr)
            Max = curr;
        if (curr < 0)
            curr = 0;
    }
    return Max;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    cout << Maximum_Subarray_Sum(arr);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}