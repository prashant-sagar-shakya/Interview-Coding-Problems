#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

struct Item
{
    double profit, weight, ratio;
};

void sortByPW(vector<Item> &items)
{
    sort(items.begin(), items.end(), [](const Item &a, const Item &b)
        { return a.ratio > b.ratio; });
}

double F_KnapSack(vector<int> &P, vector<int> &W, int M, int n)
{
    vector<Item> items(n);
    double profit = 0.0;

    for (int i = 0; i < n; i++)
    {
        items[i].profit = P[i];
        items[i].weight = W[i];
        items[i].ratio = (double)P[i] / W[i];
    }
    // Sort by ratio (Profit/Weight)
    sortByPW(items);

    for (int i = 0; i < n; i++)
        if (M >= items[i].weight)
        {
            M -= items[i].weight;
            profit += items[i].profit;
        }
        else
        {
            profit += items[i].profit * (M / items[i].weight);
            break;
        }
    return profit;
}

void Solve()
{
    int n;
    cin >> n;
    int capacity;
    cin >> capacity;
    vector<int> Profit(n), Weight(n);
    for (int i = 0; i < n; i++)
        cin >> Profit[i] >> Weight[i];
    cout << "Total Profit: " << F_KnapSack(Profit, Weight, capacity, n);
}

int main()
{
    fastio();
    Solve();
    return 0;
}
