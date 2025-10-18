#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<int> twoSum(vector<int> &arr, int target)
{
    int l = 0;              // Left pointer
    int r = arr.size() - 1; // Right pointer
    while (l < r)
    {
        int sum = arr[l] + arr[r]; // Current sum of the two pointers

        if (sum == target)         // Found the pair
            return {l + 1, r + 1}; // Return 1-based indices
        else if (sum < target)     // Sum too small, move left pointer right to increase sum
            l++;
        else // Sum too large, move right pointer left to decrease sum
            r--;
    }
    // No valid pair found (problem guarantees one solution)
    return {-1, -1};
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
    vector<int> res = twoSum(arr, target);

    for (int &i : res)
        cout << i << " ";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}