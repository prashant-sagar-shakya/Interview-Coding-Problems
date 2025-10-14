#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int Maximum_Subarray_Sum(vector<int> &arr, int k)
{
    int sum = 0, result = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    int i = 0, j = k;
    while (j < arr.size())
    {
        result = max(sum, result);
        sum = sum - arr[i] + arr[j];
        i++;
        j++;
    }
    return sum;
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
    cout << Maximum_Subarray_Sum(arr, k);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}