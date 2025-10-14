#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

long long factorial(int n)
{
    long long fact = 1;
    if (n == 0 || n == 1)
        return 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

long long Anagrams(string s)
{
    long long res = factorial(s.length());
    unordered_map<char, int> mpp;
    for (int i = 0; i < s.length(); i++)
        mpp[s[i]]++;
    long long occ_mul = 1;
    for (auto &i : mpp)
        occ_mul = occ_mul * factorial(i.second);
    return res / occ_mul;
}

int countAnagrams(string s)
{
    stringstream ss(s);
    long long res = 1;
    string word;
    vector<string> words;
    while (ss >> word)
        res = (res * Anagrams(word)) % 1000000007;
    return res;
}

// Your code here
// For Advance version use Binary Exponentation with Modular Inverse to find factorial efficiently in CPP for large numbers
void Solve()
{
    string s;
    cin >> s;
    cout << countAnagrams(s);
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}

// Efficient Implementation using Fermat's Little Theorem
/*
class Solution
{
    const int mod = 1e9 + 7;

    long long factorial(int n)
    {
        long long result = 1;
        for (int i = 2; i <= n; ++i)
            result = (result * i) % mod; // apply mod to avoid overflow
        return result;
    }

    // Count unique permutations of a string (mod-safe)
    long long countPermutations(const string &s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        long long numerator = factorial(s.size());
        long long denominator = 1;

        for (auto &[ch, count] : freq)
        {
            denominator = (denominator * factorial(count)) % mod;
        }

        // Use modular inverse for division
        return (numerator * modInverse(denominator, mod)) % mod;
    }

    // Fermat's little theorem: a^(m-2) mod m (if m is prime)
    long long modInverse(long long a, int m)
    {
        return power(a, m - 2, m);
    }

    // Fast exponentiation
    long long power(long long a, long long b, int m)
    {
        long long result = 1;
        a = a % m;
        while (b > 0)
        {
            if (b % 2 == 1)
                result = (result * a) % m;
            a = (a * a) % m;
            b /= 2;
        }
        return result;
    }

public:
    int countAnagrams(string s)
    {
        vector<string> words;
        stringstream ss(s);
        string word;

        while (ss >> word)
        {
            words.push_back(word);
        }

        long long ans = 1;
        for (const string &word : words)
        {
            ans = (ans * countPermutations(word)) % mod;
        }

        return (int)ans;
    }
};
*/