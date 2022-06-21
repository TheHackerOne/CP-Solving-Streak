#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int lo, int hi, int &cnt){
    int mid = (lo + hi)/2;
    vector<int> temp(hi-lo+1);

    int i = lo, j = mid+1, k = 0;
    while(i <= mid and j <= hi){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
            cnt += (mid-i+1);
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= hi){
        temp[k++] = arr[j++];
    }

    for(int i=lo;i<=hi;i++){
        arr[i] = temp[i-lo];
    }
}

void mergeSort(vector<int> &arr, int lo, int hi, int &cnt){
    int mid = (lo + hi)/2;
    // base case    
    if(lo >= hi) return;

    // main logic
    mergeSort(arr, lo, mid, cnt);
    mergeSort(arr, mid+1, hi, cnt);
    merge(arr, lo, hi, cnt);
}

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt = 0;
    mergeSort(arr, 0, n-1, cnt);
    cout<<cnt<<endl;
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