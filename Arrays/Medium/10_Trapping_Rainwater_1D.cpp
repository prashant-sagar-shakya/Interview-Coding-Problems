#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Function to calculate total trapped rainwater
int Trapping_RW(vector<int> &arr)
{
    int res = 0;                          // Stores total trapped water
    int left = 0, right = arr.size() - 1; // Two pointers
    int lmax = 0, rmax = 0;               // Track max height from left & right
    // Process the array from both ends
    while (left <= right)
    {
        // Case 1: Right side is the limiting wall
        if (rmax <= lmax)
        {
            // Water trapped depends on the right maximum
            res += max(0, rmax - arr[right]);
            // Update right maximum height
            rmax = max(rmax, arr[right]);
            // Move right pointer inward
            right--;
        }
        // Case 2: Left side is the limiting wall
        else
        {
            // Water trapped depends on the left maximum
            res += max(0, lmax - arr[left]);
            // Update left maximum height
            lmax = max(lmax, arr[left]);
            // Move left pointer inward
            left++;
        }
    }
    // Return total trapped water
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
    cout << Trapping_RW(arr);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}