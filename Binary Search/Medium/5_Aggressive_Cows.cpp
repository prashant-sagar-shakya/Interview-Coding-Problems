#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// You are given an array arr of size n representing the positions of stalls and an integer k representing the number of aggressive cows.Your task is to assign stalls to the k cows such that the minimum distance between any two cows is as large as possible.Return the largest possible minimum distance.For example, if n = 3, k = 2, and arr = {1, 2, 3}.

// Function to check if cows can be placed with at least 'dist' distance apart
bool canPlace(vector<int> &arr, int cows, int dist)
{
    int count = 1;        // Place first cow in first stall
    int lastPos = arr[0]; // Track last placed cow position

    // Try placing remaining cows
    for (int i = 1; i < arr.size(); i++)
    {
        // If current stall is far enough from the last cow
        if (arr[i] - lastPos >= dist)
        {
            count++;           // Place next cow
            lastPos = arr[i];  // Update last cow position
            if (count == cows) // All cows placed successfully
                return true;
        }
    }
    return false; // Not possible to place all cows
}

// Function to find the largest minimum distance between cows
int aggressiveCows(vector<int> &arr, int cows)
{
    sort(arr.begin(), arr.end());        // Sort stall positions
    int low = 1;                         // Minimum possible distance
    int high = arr.back() - arr.front(); // Maximum possible distance
    int ans = -1;                        // Store the best (maximized) distance

    // Binary search on distance
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Mid distance to check
        if (canPlace(arr, cows, mid))
        {
            ans = mid; // Possible, try for larger distance
            low = mid + 1;
        }
        else
            high = mid - 1; // Not possible, reduce distance
    }
    return ans; // Return largest minimum distance
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    int cows;
    cin >> cows;
    cout << aggressiveCows(arr, cows);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}