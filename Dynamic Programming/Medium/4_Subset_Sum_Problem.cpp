#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

bool isSubsetSum(vector<int> &arr, int sum)
{
    // dp[i][j] = true if sum j can be formed using first i elements
    vector<vector<bool>> dp(arr.size() + 1, vector<bool>(sum + 1, false));
    // base case: sum = 0 can always be formed (by taking no elements)
    for (int i = 0; i <= arr.size(); i++)
        dp[i][0] = true;
    // fill dp table iteratively
    for (int i = 1; i <= arr.size(); i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j) // either include or exclude current element
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else // can't include current element
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[arr.size()][sum];
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    int sum;
    cin >> sum;
    cout << boolalpha << isSubsetSum(arr, sum);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}