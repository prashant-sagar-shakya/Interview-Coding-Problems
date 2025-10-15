#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int Maximum_Subarray_Sum(vector<int> &arr, int k)
{
    if (arr.size() < k)
        return 0;
        
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    int result = sum;
    int i = 0, j = k;
    while (j < arr.size())
    {
        sum = sum - arr[i] + arr[j];
        result = max(result, sum);
        i++;
        j++;
    }
    return result;
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