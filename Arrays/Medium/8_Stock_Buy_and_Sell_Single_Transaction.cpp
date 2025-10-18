#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Stock Must be bought before sold

int SBS_ST(vector<int> &prices)
{
    // Assume the prices on day 1 is minimum so far
    int minSofar = prices[0];
    int res = 0; // Result to store max profit
    for (int i = 1; i < prices.size(); i++)
    {
        // Update minSofar if a lower price is found
        minSofar = min(minSofar, prices[i]);
        // Calculating today's profit if we buy at minSofar price and sold today -> Profit = today's price - minSofar
        int ProfitToday = prices[i] - minSofar;
        res = max(res, ProfitToday); // Storing the max profit till now
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
    cout << SBS_ST(arr);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}