#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int searchInRotatedArray(vector<int> &arr, int target)
{
    int n = arr.size();         // Store size of the array
    int start = 0, end = n - 1; // Initialize binary search boundaries
    int mid = 0;                // Variable to store mid index

    // Standard binary search loop
    while (start <= end)
    {
        mid = start + (end - start) / 2; // Calculate middle index
        // If target found at mid, return index
        if (arr[mid] == target)
            return mid;
        // Check if the left half is sorted
        else if (arr[start] <= arr[mid])
        {
            // If target lies within the left sorted part
            if (arr[start] <= target && target <= arr[mid])
                end = mid - 1; // Move to left half
            else
                start = mid + 1; // Move to right half
        }
        // Otherwise, the right half must be sorted
        else
        {
            // If target lies within the right sorted part
            if (arr[mid] <= target && target <= arr[end])
                start = mid + 1; // Move to right half
            else
                end = mid - 1; // Move to left half
        }
    }
    return -1; // Target not found
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    int target;
    cin >> target;
    cout << searchInRotatedArray(arr, target);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}