#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<int> FindIntersection(vector<int> a, vector<int> b)
{
    vector<int> Intersection;            // Vector to store intersection result
    int i = 0, j = 0;                    // declaring two ointers i and j to iterate over array a and b respectively
    while (i < a.size() && j < b.size()) // If element exists in both arrays then only include it
    {
        if (a[i] == b[j])
        {
            if (Intersection.size() == 0 || Intersection.back() != a[i]) // No element repeatition allowed
                Intersection.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j]) // Because both arrays are sorted then if a[i] < b[j] then move i pointer 1 step ahead
            i++;
        else // Because both arrays are sorted then if a[i] > b[j] then move j pointer 1 step ahead
            j++;
    }
    return Intersection;
}
// Your code here
void Solve()
{
    int m, n; // sizes of both vectors
    vector<int> a(m);
    vector<int> b(n);

    // Taking Input
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;

    vector<int> c = FindIntersection(a, b);
    for (int &i : c)
        cout << i << " ";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}