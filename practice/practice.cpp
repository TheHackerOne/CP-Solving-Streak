#include<bits/stdc++.h>
using namespace std;

int recur(int idx, int n, vector<int> &arr, bool buy){
    // base case
    if(idx == n){
        return INT_MIN;
    }

    // main logic
    if(buy){
        int res1 = arr[idx];
        int res2 = recur(idx+1, n, arr, buy);
        return max(res1, res2);
    }else{
        int res1 = recur(idx+1, n, arr, true)-arr[idx];
        int res2 = recur(idx+1, n, arr, false);
        return max(res1, res2);
    }
}

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<recur(0, n, arr, false); // buy is false

}

int main() {
#ifndef ONLINE_JUDGE  
    freopen("Error.txt", "w", stderr);
#endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}