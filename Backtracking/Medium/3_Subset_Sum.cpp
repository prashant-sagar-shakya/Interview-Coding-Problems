#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Recursive helper function to check subset sum
bool isSubsetSumHelper(vector<int> &arr, int n, int sum)
{
    // Base Case 1: If sum becomes 0 → subset found
    if (sum == 0)
        return true;
    // Base Case 2: If no elements left and sum is not 0 → no subset
    if (n == 0)
        return false;
    // If current element is greater than remaining sum, skip it
    if (arr[n - 1] > sum)
        return isSubsetSumHelper(arr, n - 1, sum);

    // Two choices for each element:
    // 1. Include it  → reduce sum
    // 2. Exclude it  → move to next element
    return isSubsetSumHelper(arr, n - 1, sum - arr[n - 1]) ||
           isSubsetSumHelper(arr, n - 1, sum);
}

// Wrapper function
bool isSubsetSum(vector<int> &arr, int sum)
{
    int n = arr.size();
    return isSubsetSumHelper(arr, n, sum);
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