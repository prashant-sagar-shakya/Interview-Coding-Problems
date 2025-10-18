#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Also known as merge overlapping intervals

vector<vector<int>> MergeOverlap(vector<vector<int>> &arr)
{
    if (arr.empty())
        return {};

    // Sort intervals by starting time
    sort(arr.begin(), arr.end());

    // Start with the first interval
    vector<vector<int>> res;
    res.push_back(arr[0]);

    // Traverse remaining intervals
    for (int i = 0; i < arr.size(); i++)
    {
        vector<int> &last = res.back(); // Last interval in result
        vector<int> &curr = arr[i];     // Current traversing interval

        // Case 1: If Overlap -> Merge with last interval
        if (curr[0] <= last[1])
            last[1] = max(last[1], curr[1]);

        // Case 2: No Overlap -> Add as a new interval
        else
            res.push_back(curr);
    }
    return res;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<vector<int>> Intervals(n, vector<int>(2));

    // Input
    for (auto &arr : Intervals)
        for (int &i : arr)
            cin >> i;
    vector<vector<int>> Result = MergeOverlap(Intervals);

    // Output
    cout << "[";
    for (int i = 0; i < Result.size(); i++)
    {
        cout << "[" << Result[i][0] << "," << Result[i][1] << "]";
        if (i != Result.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}