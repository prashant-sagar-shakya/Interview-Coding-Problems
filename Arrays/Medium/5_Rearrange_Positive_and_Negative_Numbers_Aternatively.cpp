#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// This problem is also known as Rearrange Array Elements by Sign
vector<int> RearrangePN(vector<int> &arr)
{
    int n = arr.size();
    // Initializing an result array of size n
    vector<int> res(n, 0);
    // Initializing two pointers to track even and odd indices for positive and negative integers respectively
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            // Placing the positive integer at the desired index in res and incrementing posIndex by 2
            res[posIndex] = arr[i];
            posIndex += 2;
        }
        else
        {
            // Placing the negative integer at the desired index in res and incrementing negIndex by 2
            res[negIndex] = arr[i];
            negIndex += 2;
        }
    }
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
    vector<int> res = RearrangePN(arr);
    for (int &i : res)
        cout << i << " ";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}