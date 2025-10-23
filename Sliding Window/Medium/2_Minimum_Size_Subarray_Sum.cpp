#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int minSubArrayLen(vector<int> &arr, int target)
{
    int l = 0, r = 0;     // Left and right pointers for the sliding window
    int sum = 0;          // Current sum of elements in the window
    int minLen = INT_MAX; // Stores the minimum subarray length found so far

    while (r < arr.size())
    {
        sum += arr[r]; // Add the current element to the window
        // If the current sum meets or exceeds the target, try shrinking the window
        while (sum >= target)
        {
            // Update the minimum length if the current window is smaller
            minLen = min(minLen, r - l + 1);
            // Subtract the leftmost element and move the left pointer ahead
            sum -= arr[l];
            l++;
        }
        r++; // Move the right pointer to expand the window
    }
    // If no subarray meets the condition, return 0; otherwise, return the smallest length
    return (minLen == INT_MAX) ? 0 : minLen;
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
    cout << minSubArrayLen(arr, target);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}