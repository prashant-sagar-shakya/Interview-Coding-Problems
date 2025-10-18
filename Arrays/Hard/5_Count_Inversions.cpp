#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// An inversion is a pair of indices (i,j) with i < j and arr[i] > arr[j]

// Approach:
/*
Step 1: Split the array in two halves
Step 2: Count inversions in left half, right half recursively
Step 3: While merging two sorted halves:
    -> If left[i] <= right [j] => No inversions
    -> Else if right[j] < left[i] => All remaing (n1 - i) elements in left subarray are greater than right[j], so add (n1 - i) to result
*/

#include <bits/stdc++.h>
using namespace std;

// Function to count inversions while merging two sorted halves
int CountAndMerge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    vector<int> left(n1), right(n2);

    // Copy data into temporary left and right subarrays
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    int res = 0; // To store inversion count

    // Merge both subarrays and count inversions
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++]; // No inversion because left[i] is smaller
        else
        {
            // Inversion occurs when left[i] > right[j]
            // Since left[] and right[] are sorted,
            // all remaining elements in left[i...n1-1] will form inversions with right[j]
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }
    // Copy remaining elements (if any)
    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];

    return res; // Return total inversions found during this merge
}

int CountInversion(vector<int> &arr, int l, int r)
{
    int res = 0;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        res += CountInversion(arr, l, m);     // Left Half
        res += CountInversion(arr, m + 1, r); // Right Half
        res += CountAndMerge(arr, l, m, r);   // Cross inversions
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
    cout << CountInversion(arr, 0, n - 1);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}