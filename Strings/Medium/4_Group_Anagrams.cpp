#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<vector<string>> GroupAnagrams(vector<string> &strs)
{
    // Create an unordered map where:
    // key -> unique representation of character frequency
    // value -> list of words (strings) that share the same frequency pattern (i.e., anagrams)
    unordered_map<string, vector<string>> ansMap;

    // Iterate over each word in the input list
    for (string &s : strs)
    {
        // Step 1: Create a frequency array for 26 letters (a-z), initialized with 0
        vector<int> count(26, 0);
        // Step 2: Count frequency of each character in the current word
        for (char c : s)
            count[c - 'a']++; // Increment count for that character
        // Step 3: Convert the frequency array into a unique string key
        // Example: "eat" -> "#1#0#0#0...#1#0..." (each '#' separates counts)
        string key;
        for (int i = 0; i < 26; i++)
            key += "#" + to_string(count[i]);
        // Step 4: Store the current word under its unique key in the map
        // (All anagrams will share the same key)
        ansMap[key].push_back(s);
    }
    // Step 5: Extract the grouped anagrams from the map into a result vector
    vector<vector<string>> result;
    for (auto &pair : ansMap)
        result.push_back(pair.second); // Push all words of the same key into result
    // Step 6: Return the final list of grouped anagrams
    return result;
}

// Your code here
void Solve()
{
    int n;
    cin >> n; // Number of strings

    vector<string> strs(n);
    for (auto &s : strs)
        cin >> s; // Input strings

    vector<vector<string>> result = GroupAnagrams(strs);

    // Output in array-like format
    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j != result[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if (i != result.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}