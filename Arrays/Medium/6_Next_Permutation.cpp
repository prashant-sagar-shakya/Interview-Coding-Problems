#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void Next_Permutation(vector<int> &arr)
{
    int n = arr.size();
    int pivot = -1;
    // Pivot is the element from right which breaks the descending order
    // Finding the pivot index
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            pivot = i;
            break;
        }
    }
    // If pivot not exists, i.e, array is completely in descending order then reverse the array and return as next permutation
    if (pivot == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }
    // Find the next bigger element on right, that is greater than pivot
    for (int i = n - 1; i > pivot; i--)
    {
        if (arr[i] > arr[pivot])
        {
            // Swap pivot with that element
            swap(arr[pivot], arr[i]);
            break;
        }
    }
    // Reverse the suffix to get next permutation
    reverse(arr.begin() + pivot + 1, arr.end());
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    Next_Permutation(arr);

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