#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int Sum(vector<int> &arr, int i, int j)
{
    int sum = 0;
    for (int loop = i; loop <= j; loop++)
        sum += arr[loop];
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
    int i, j;
    cin >> i>>j;
    cout << "Sum Between " << i << " and " << j << " is: " << Sum(arr, i, j) << endl;
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}