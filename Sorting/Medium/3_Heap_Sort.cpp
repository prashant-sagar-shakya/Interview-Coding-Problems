#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// To Heapify a subtree rooted with node i
void Heapify(vector<int> &arr, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left index = 2*i + 1
    int r = 2 * i + 2; // right index = 2*i + 2
    if (l < n && arr[l] > arr[largest]) // If left child is larger than root
        largest = l;
    if (r < n && arr[r] > arr[largest]) // If right child is larger than largest so far
        largest = r;
    if (largest != i) // If largest is not root
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

void Heap_Sort(vector<int> &arr)
{
    int n = arr.size();
    // Build heap (rearrange vector)
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); // Move current root to end
        Heapify(arr, i, 0); // Call max heapify on the reduced heap
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
    Heap_Sort(arr);
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