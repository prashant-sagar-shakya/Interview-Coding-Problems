#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void RotateLeft(vector<int> arr, int k)
{
    k %= arr.size();
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());

    // Printing
    for (int &i : arr)
        cout << i << " ";
}

void RotateRight(vector<int> arr, int k)
{
    k %= arr.size();
    reverse(arr.end() - k, arr.end());
    reverse(arr.begin(), arr.end() - k);
    reverse(arr.begin(), arr.end());

    // Printing
    for (int &i : arr)
        cout << i << " ";
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
    cout << "Left Rotated by " << k << " Places: ";
    RotateLeft(arr, k);
    cout << endl;
    cout << "Right Rotated by " << k << " Places: ";
    RotateRight(arr, k);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}