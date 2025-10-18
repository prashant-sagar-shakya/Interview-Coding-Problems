#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
    
// You're allowed to buy and sell multiple times even on next day

int SBS_MT(vector<int> &prices)
{
    int res = 0; // Total Profit
    // Go through each pair of days
    for (int i = 1; i < prices.size(); i++)
    {
        // If prices today is more than prices yesterday then, profit = total - yesterday
        if (prices[i] > prices[i - 1])
            res = res + prices[i] - prices[i - 1];
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
    cout << SBS_MT(arr);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}