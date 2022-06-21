#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    int lo = 0, hi = n-1;
    int res = -1;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(arr[mid] == target){
            res = mid;
            break;
        }else if(arr[mid] > arr[0]){
            if(target >= arr[0] and target <= arr[mid]){
                hi = mid;
            }else{
                lo = mid+1;
            }
        }else if(arr[mid] < arr[n-1]){
            if(target >= arr[mid] and target <= arr[n-1]){
                lo = mid;
            }else{
                hi = mid-1;
            }
        }
    }

    cout<<res<<endl;
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