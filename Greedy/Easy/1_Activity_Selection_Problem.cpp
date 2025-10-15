#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Sort by finishing time
bool sortPair(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

vector<int> ASP(vector<int> &s, vector<int> &f, int n)
{
    vector<pair<int, int>> SF;
    for (int i = 0; i < n; i++)
        SF.push_back({s[i], f[i]});

    // Sort according to finish times
    sort(SF.begin(), SF.end(), sortPair);

    vector<int> result;
    int lastFinish = SF[0].second;
    result.push_back(1); // First activity selected

    for (int i = 1; i < n; i++)
    {
        if (SF[i].first >= lastFinish)
        {
            result.push_back(i + 1); // Activity index (1-based)
            lastFinish = SF[i].second;
        }
    }
    return result;
}

void Solve()
{
    int n;
    cin >> n;

    vector<int> s(n), f(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        cin >> f[i];

    vector<int> result = ASP(s, f, n);

    cout << "Total no. of activities: " << result.size() << "\n";
    cout << "Selected Activities: ";
    for (int i : result)
        cout << i << " ";
}

int main()
{
    fastio();
    Solve();
    return 0;
}
