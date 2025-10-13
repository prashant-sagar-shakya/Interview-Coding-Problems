#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void Selection_Sort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int Min_Idx = i;
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[j] < arr[Min_Idx])
                Min_Idx = j;
        if (Min_Idx != i)
            swap(arr[i], arr[Min_Idx]);
    }
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    Selection_Sort(arr);
    for (int &i : arr)
        cout << i << " ";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}