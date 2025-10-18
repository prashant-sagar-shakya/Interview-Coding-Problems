#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Function to generate all subsets of the input array using bitwise operators
vector<vector<int>> getPowerSet(vector<int> &arr)
{
    int n = arr.size();
    int subsets = 1 << n; // Calculate the total number of subsets using bitwise left shift operator
    vector<vector<int>> ans;
    for (int num = 0; num < subsets; num++) // Iterate through all numbers from 0 to subsets - 1
    {
        vector<int> subset; // Initialize a vector to store the current subset
        // Iterate through each bit position in the current number
        for (int i = 0; i < n; i++)
        {
            // Check if the ith bit of the current number is set
            if (num & (1 << i)) // If the bit is set, add the corresponding element from the input array to the subset
                subset.push_back(arr[i]);
        }
        ans.push_back(subset); // Add the current subset to the list of subsets
    }
    return ans; // Return the vector of all subsets
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    vector<vector<int>> Subsets = getPowerSet(arr);
    // Printing the subsets
    for (auto subset : Subsets)
    {
        for (int &i : subset)
            cout << i << " ";
        cout << endl;
    }
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}