#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int LargestElement(vector<int> &arr)
{
    int Maxi = INT_MIN;
    for (int &i : arr)
        if (i > Maxi)
            Maxi = i;
    return Maxi;
}

int SmallestElement(vector<int> &arr)
{
    int Mini = INT_MAX;
    for (int &i : arr)
        if (i < Mini)
            Mini = i;
    return Mini;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    cout << "Largest Element: " << LargestElement(arr) << endl;
    cout << "Smallest Element: " << SmallestElement(arr) << endl;
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}