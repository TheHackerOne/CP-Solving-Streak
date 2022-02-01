#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    return a > b;
}

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n), arr2(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++){
        cin>>arr2[i];
        mp[arr2[i]]++;
    }
    sort(arr.begin(), arr.end());
    sort(arr2.begin(), arr2.end());
    for(int i=0;i<n;i++){
        int num = arr[i];
        int tnum = arr[i]+1;
        if(mp[num] == 0 && mp[tnum] == 0){
            cout<<"NO"<<endl;
            return;
        }else if(mp[num] != 0){
            mp[num]--;
        }else{
            mp[tnum]--;
        }
    }
    cout<<"YES"<<endl;
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