#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int Maximum_Product_Subarray(vector<int> &arr)
{
    int minProd = arr[0];
    int maxProd = arr[0];
    int res = arr[0];

    // Traverse the array from index 1
    for (int i = 1; i < arr.size(); i++)
    {
        // If the current element is -ve -> swap maxProd and minProd because multiplying with -ve reverses the roles
        if (arr[i] < 0)
            swap(maxProd, minProd);
        // Update maxProd and minProd
        // maxProd will store max of -> current element or maxProd * current element
        maxProd = max(arr[i], maxProd * arr[i]);
        //  Simmilarly minProd will store min of current element or minProd * current element
        minProd=min(arr[i], minProd*arr[i]);

        // Update answer with max bound so far
        res = max(res, maxProd);
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
    cout << Maximum_Product_Subarray(arr);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}