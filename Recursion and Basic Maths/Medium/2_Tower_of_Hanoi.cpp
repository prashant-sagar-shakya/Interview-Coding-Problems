#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int moves = 0;

int towerOfHanoi(int n, int from, int to, int aux)
{
    if (n == 0)
        return 0; // Base case: no disk to move

    // Move n-1 disks from 'from' to 'aux' using 'to' as auxiliary
    towerOfHanoi(n - 1, from, aux, to);
    moves++; // Move the largest disk from 'from' to 'to'
    // Move n-1 disks from 'aux' to 'to' using 'from' as auxiliary
    towerOfHanoi(n - 1, aux, to, from);

    return moves; // Return total moves
}

// Your code here
void Solve()
{
    int disc, src, target, aux;
    cin >> disc >> src >> target >> aux;
    int totalMoves = towerOfHanoi(disc, src, target, aux);
    cout << totalMoves << endl;
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}