#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> arr1, arr2;
    for(int i=0;i<n;i++){
        if(i%2 == 0) arr1.push_back(arr[i]);
        else arr2.push_back(arr[i]);
    }
    cout<<abs(arr1[(arr1.size()-1)/2]-arr2[(arr2.size()-1)/2])<<endl; 

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