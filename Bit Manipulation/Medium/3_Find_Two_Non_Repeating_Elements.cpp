#include <bits/stdc++.h>
using namespace std;

// This Problem is also known as Single Number III on Leetcode

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<int> Two_Non_Repeating(vector<int> &arr)
{
    int Xor = 0;

    // Find linear xor to remove all the duplicates
    for (int i = 0; i < arr.size(); i++)
        Xor = Xor ^ arr[i];

    int r; // Declare a variable to store the rightmost bit set in Xor

    // Check if Xor is equal to INT_MIN (minimum value of int)
    if (Xor == INT_MIN) // If Xor is INT_MIN, set rightmost to INT_MIN
        r = INT_MIN;
    else // Compute the rightmost set bit in Xor
        r = (Xor & (Xor - 1)) ^ Xor;
    int b1 = 0, b2 = 0; // Initialize buckets to store numbers that are set at the corresponding bit or not
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] & r) // If the rightmost bit set in arr[i] is also set in rightmost, XOR arr[i] with bucket1
            b1 = arr[i] ^ b1;
        else // If the rightmost bit set in arr[i] is not set in rightmost, XOR arr[i] with bucket2
            b2 = arr[i] ^ b2;
    }
    // Return the two unique numbers found in b1 and b2
    return {b1, b2};
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    vector<int> res = Two_Non_Repeating(arr);
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