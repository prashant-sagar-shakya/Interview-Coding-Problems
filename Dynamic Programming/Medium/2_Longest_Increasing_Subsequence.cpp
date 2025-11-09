#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();   // total number of elements in the array
    vector<int> dp(n, 1); // dp[i] stores the length of the longest increasing subsequence ending at index i
    for (int i = 0; i < n; ++i)
    { // iterate through each element as potential end of subsequence
        for (int j = 0; j < i; ++j)
        {                                             // check all previous elements before i
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) // if a valid increasing relation and better length found
                dp[i] = dp[j] + 1;                    // update dp[i] with the new longer subsequence length
        }
    }
    return *max_element(dp.begin(), dp.end()); // return the maximum subsequence length among all positions
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    cout << lengthOfLIS(arr);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}