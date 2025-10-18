#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int RemoveDuplicates(vector<int> &arr)
{
    int j = 1;
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] != arr[i - 1])
            arr[j++] = arr[i];
    return j;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    int TerminationPoint = RemoveDuplicates(arr);
    for (int i = 0; i < TerminationPoint; i++)
        cout << arr[i] << " ";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}