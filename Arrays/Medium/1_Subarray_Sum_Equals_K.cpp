#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int SSE_K(vector<int> &arr, int k)
{
    unordered_map<int, int> mpp; // Stores frequency of each prefix sum encountered
    int sum = 0;                 // Running prefix sum
    int cnt = 0;                 // Count of subarrays with sum exactly equal to K
    mpp[0] = 1;                  // Base case: one way to have sum = 0 before starting (empty subarray)

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i]; // Update running sum with current element
        // Find the required prefix sum that would make the subarray sum = k
        int complement = sum - k;
        // If that prefix sum exists, it means there are mpp[complement] subarrays ending at i
        if (mpp.find(complement) != mpp.end())
            cnt += mpp[complement];
        // Record the current prefix sum in the map (increment its frequency)
        mpp[sum]++;
    }
    return cnt; // Total number of subarrays with sum = k
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
    cout << SSE_K(arr, k);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}