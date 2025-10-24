#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// This problem is also known as Book Allocation Problem
// You are given an array arr of size N representing the number of pages in N books and an integer B representing the number of students. You need to allocate books to all students such that each student gets at least one book, the books allocated to each student are contiguous, and the maximum number of pages assigned to any student is minimized. Return the minimum possible value of this maximum, or -1 if allocation is not possible.

int allocateBooks(vector<int> &arr, int students)
{
    int n = arr.size();
    if (n < students)
        return -1;          // Not enough books for each student
    int total = 0, Max = 0; // total = sum of pages, Max = max pages in a single book

    for (int i = 0; i < n; i++)
    {
        total += arr[i];
        Max = max(Max, arr[i]);
    }

    int low = Max, high = total, ans = -1; // Search space: [Max, total]

    // Binary search on the answer
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Possible max pages per student
        int count = 1, pages = 0;         // count = number of students used
        // Check if allocation possible with current mid as limit
        for (int i = 0; i < n; i++)
        {
            pages += arr[i];
            if (pages > mid)
            {
                count++;        // Assign next student
                pages = arr[i]; // Start new allocation
            }
        }
        if (count <= students)
        {
            // Allocation possible
            ans = mid;
            high = mid - 1; // Try smaller maximum
        }
        else
            low = mid + 1; // Increase limit
    }
    return ans; // Minimum possible maximum pages
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    int students;
    cin >> students;
    cout << allocateBooks(arr, students);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}