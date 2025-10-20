#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Function to find all leaders in the array
// A leader is an element that is greater than or equal to all the elements to its right.
vector<int> Leaders(vector<int> &arr)
{
    vector<int> res;   // To store all leader elements
    int Max = INT_MIN; // Initialize with the smallest possible integer
    // Traverse from right to left (as the last element is always a leader)
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        // If current element is greater than or equal to the maximum so far, it is a leader
        if (arr[i] >= Max)
        {
            Max = arr[i];          // Update the maximum element seen so far
            res.push_back(arr[i]); // Add current element to result
        }
    }
    // Since we traversed from right to left, leaders are stored in reverse order
    reverse(res.begin(), res.end());
    return res; // Return list of leaders from left to right
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    vector<int> res = Leaders(arr);

    for (int &i : arr)
        cout << i << " ";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}