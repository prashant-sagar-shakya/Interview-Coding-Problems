#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Approach:
// Sort jobs in descending order of profit.
// For each job, try to schedule it in the latest available slot before its end time.
// If that slot is free, assign it and add the profit.
// Continue until all jobs are considered.

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    vector<tuple<int, int, int>> jobs;
    // Combine start, end, and profit into one tuple for easy sorting
    for (int i = 0; i < n; i++)
        jobs.push_back({endTime[i], startTime[i], profit[i]});
    // Sort jobs in descending order of profit
    sort(jobs.begin(), jobs.end(), [](auto &a, auto &b)
         { return get<2>(a) > get<2>(b); });
    // Find the maximum possible end time to size the time slots array
    int maxEnd = *max_element(endTime.begin(), endTime.end());
    // Slot array to keep track of occupied times (-1 means free)
    vector<int> slot(maxEnd + 1, -1);
    int totalProfit = 0;

    // Try to schedule each job
    for (int i = 0; i < n; i++)
    {
        int end = get<0>(jobs[i]);
        int start = get<1>(jobs[i]);
        int prof = get<2>(jobs[i]);
        // Try to place this job at the latest possible free time slot
        for (int t = end; t > start; t--)
        {
            if (slot[t] == -1)
            {
                slot[t] = i;         // Mark this slot as occupied by this job
                totalProfit += prof; // Add profit to total
                break;
            }
        }
    }
    // Return total profit achieved
    return totalProfit;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> startTime(n), endTime(n), profit(n);
    for (int &i : startTime)
        cin >> i;
    for (int &i : endTime)
        cin >> i;
    for (int &i : profit)
        cin >> i;
    cout << jobScheduling(startTime, endTime, profit);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}