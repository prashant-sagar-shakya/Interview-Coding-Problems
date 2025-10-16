#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int FindUnique(vector<int> &arr)
{
    // To find unique element xor all the elements of the array
    int res = 0;
    for (int &x : arr)
        res ^= x;
    return res;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    cout << FindUnique(arr);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}