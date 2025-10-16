#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<vector<int>> allSubsets;

void generate(vector<int> &subset, int i, vector<int> &arr)
{
    if (i == arr.size())
    {
        allSubsets.push_back(subset);
        return;
    }
    // ith element not included in subset
    generate(subset, i + 1, arr);
    // ith element included in subset
    subset.push_back(arr[i]);
    generate(subset, i + 1, arr);
    subset.pop_back();
}
vector<vector<int>> subsets(vector<int> &arr)
{
    vector<int> empty;
    generate(empty, 0, arr);
    return allSubsets;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    vector<vector<int>> Subsets = subsets(arr);
    // Printing the subsets
    for (auto subset : allSubsets)
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