#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int maxArea(vector<int> &height)
{
    int maxArea = 0;               // Variable to store the maximum area found so far
    int left = 0;                  // Pointer starting from the left end
    int right = height.size() - 1; // Pointer starting from the right end

    while (left < right)
    {
        // Calculate the area between the two lines
        // Width = distance between left and right pointers
        // Length/Height = minimum of the two heights
        maxArea = max(maxArea, (right - left) * min(height[left], height[right]));

        // Move the pointer at the shorter line inward, This may help find a taller line and possibly a larger area
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return maxArea;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int &i : height)
        cin >> i;
    cout << maxArea(height);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}