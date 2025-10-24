#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int findPeakElement(vector<int> &arr)
{
    int n = arr.size(); // Store array size
    // Edge cases: array of size 1 or peak at boundaries
    if (n == 1)
        return 0; // Only one element → peak at index 0
    if (arr[0] > arr[1])
        return 0; // Peak at first element
    if (arr[n - 1] > arr[n - 2])
        return n - 1; // Peak at last element

    int start = 1;   // Skip first element (already checked)
    int end = n - 2; // Skip last element (already checked)

    // Binary search to find peak
    while (start <= end)
    {
        int mid = start + (end - start) / 2; // Compute mid index
        // Check if mid is a peak element
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;
        // If left neighbor is greater → move left
        if (arr[mid - 1] > arr[mid])
            end = mid - 1;
        // Otherwise, move right
        else
            start = mid + 1;
    }
    return -1; // Should never reach here if input is valid
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    cout << findPeakElement(arr);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}