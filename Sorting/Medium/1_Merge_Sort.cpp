#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Merges two subarrays of arr[], First subarray is arr[left..mid] and Second subarray is arr[mid+1..right]
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1, n2 = right - mid;
    // Create temp vectors
    vector<int> L(n1), R(n2);
    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back into arr[left..right]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
        k++;
    }
    // Copy the remaining elements of L[], if there are any
    while (i < n1)
        arr[k++] = L[i++];
    // Copy the remaining elements of R[], if there are any
    while (j < n2)
        arr[k++] = R[j++];
}

void Merge_Sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        Merge_Sort(arr, low, mid);
        Merge_Sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
    Merge_Sort(arr, 0, arr.size() - 1);
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