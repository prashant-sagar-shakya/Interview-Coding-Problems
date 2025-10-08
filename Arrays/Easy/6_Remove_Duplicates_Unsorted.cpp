#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    // Using Set Data Structure for Keeping only Unique Elements
    set<int> st;
    for (int i = 0; i < n; i++)
    st.insert(arr[i]);

    // Printing Set Elements
    for(auto &i:st)
        cout << i << " ";
}

// Driver code
int main() {
    fastio();
    Solve();
    return 0;
}