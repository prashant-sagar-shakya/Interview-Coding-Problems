#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void DNF(vector<int>&arr){
    int left = 0, right = arr.size() - 1, i=0;
    while(i<=right){
        if(arr[i]==0){
            swap(arr[i], arr[left]);
            left++;
            i++;
        }
        else if(arr[i]==2){
            swap(arr[i], arr[right]);
            right--;
        }
        else
            i++;
    }
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    DNF(arr);
    for(int &i:arr)
        cout << i << " ";
}

// Driver code
int main() {
    fastio();
    Solve();
    return 0;
}