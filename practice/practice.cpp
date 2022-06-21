#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &arr){
    int n = arr.size();
    // base case
    if(arr[0] < arr[n-1]) return 0;
    // main logic
    int lo = 0, hi = arr.size()-1;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(arr[mid] < arr[mid-1] and arr[mid] < arr[mid+1]){
            return mid;
        }else if(arr[mid] > arr[0]){
            lo = mid;
        }else if(arr[mid] < arr[n-1]){
            hi = mid;
        }
    }
    return -1;
}

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int pivotIdx = findPivot(arr);
    cout<<arr[pivotIdx]<<endl;
}

int main() {
#ifndef ONLINE_JUDGE  
    freopen("Error.txt", "w", stderr);
#endif

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}