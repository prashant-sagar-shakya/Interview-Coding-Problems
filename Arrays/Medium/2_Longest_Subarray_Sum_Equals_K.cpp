#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// If array contains negatives also then hashing is the best way
/*
int Longest_Subarray_Sum_K(vector<int> &arr, int k)
{
    unordered_map<int, int> mpp; // Stores first occurrence of each prefix sum
    int sum = 0;                 // Running prefix sum
    int MaxLen = 0;              // Maximum length of subarray with sum = k

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i]; // Add current element to prefix sum

        // Case 1: If prefix sum itself equals k, then subarray from index 0 to i has sum k
        if (sum == k)
        MaxLen = i + 1;

        // Calculate remaining sum needed to reach k from a previous prefix
        int rem = sum - k; // If there was a prefix sum = rem, then subarray from that index+1 to i sums to k

        // Case 2: If rem exists in map, update MaxLen
        if (mpp.find(rem) != mpp.end())
        {
            int len = i - mpp[rem]; // Length of subarray with sum = k
            MaxLen = max(MaxLen, len);
        }

        // Store the first occurrence of this prefix sum
        // This ensures we get the longest subarray later
        if (mpp.find(sum) == mpp.end())
        mpp[sum] = i;
    }
    return MaxLen;
}
*/

// Using Two-Pointers and Sliding Window
int Longest_Subarray_Sum_K(vector<int> &arr, int k)
{
    int l = 0, r = 0; // Window pointers
    int sum = 0;      // Sum of current window
    int maxLen = 0;   // Maximum length found
    while (r < arr.size())
    {
        sum += arr[r]; // Add rightmost element to window
        // Shrink window from left while sum > k
        while (l <= r && sum > k)
        {
            sum -= arr[l];
            l++;
        }
        // If current window sum equals k, update maxLen
        if (sum == k)
            maxLen = max(maxLen, r - l + 1);

        r++; // Expand window to the right
    }
    return maxLen;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    int k;
    cin >> k;
    cout << Longest_Subarray_Sum_K(arr, k);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}