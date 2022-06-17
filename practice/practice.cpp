#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // find pivot index using binary search
    int low = 0, high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] < arr[mid-1] and arr[mid] < arr[mid+1]){
            ans = mid;
            break;
        }else if(arr[mid] > arr[n-1]){
            low = mid+1;
        }else if(arr[mid] < arr[0]){
            high = mid-1;
        }
    }

    cout<<ans<<endl;
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