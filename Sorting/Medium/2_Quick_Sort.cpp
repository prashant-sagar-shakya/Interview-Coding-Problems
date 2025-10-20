#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int partition(vector<int> &arr, int low, int high)
{
    // choose the pivot
    int pivot = arr[high];

    // Index of smaller element and indicates the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller elements on left side. Elements from low to i are smaller after every iteration
    for (int j = low; j <= high - 1; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);

    // move pivot after smaller elements and return its position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Quick_Sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // pivot is the partition return index of pivot
        int pivot = partition(arr, low, high);
        // recursion calls for smaller elements and greater or equals elements
        Quick_Sort(arr, low, pivot - 1);
        Quick_Sort(arr, pivot + 1, high);
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
    Quick_Sort(arr, 0, arr.size() - 1);
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