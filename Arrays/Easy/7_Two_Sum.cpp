#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<int> TwoSum(vector<int> &arr, int target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        // Finding Complement element, i.e, target = current element + Its complement
        int complement = target - arr[i];
        // Searching the complement in the map, if found then return with corresponding index
        if (mpp.find(complement) != mpp.end())
            return {mpp[complement], i};
        // Complement not found in map then store the current element index in map for further checkings.
        mpp[arr[i]] = i;
    }
    return {};
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
    vector<int> result = TwoSum(arr, target);
    cout << result[0] << " " << result[1];
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}