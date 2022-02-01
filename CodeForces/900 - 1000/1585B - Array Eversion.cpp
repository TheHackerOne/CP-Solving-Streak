#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    return a > b;
}

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int lastEle = arr[n-1];
    int maxEle = *max_element(arr.begin(), arr.end());
    if(lastEle == maxEle) {
        cout<<0<<endl;
        return;
    }
    int idx = n-1, count = 0;
    vector<int> r;
    bool flag = true;
    while(flag){
        while(arr[idx] <= lastEle) idx--;
        lastEle = arr[idx];
        r.push_back(lastEle);
        if(lastEle == maxEle) break;
    }

    cout<<r.size()<<endl;
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