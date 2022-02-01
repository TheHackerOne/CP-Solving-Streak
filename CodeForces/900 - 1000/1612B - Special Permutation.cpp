#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin>>n>>a>>b;
    vector<int> arr(n, -1);
    arr[0] = a,arr[n-1] = b;
    int first = 1, last = n-2;
    for(int i=1;i<=n;i++){
        if(i != a && i!= b){
            if(i < b && last >= n/2){
                arr[last--] = i;
            }else if(i > a && first < n/2){
                arr[first++] = i;
            }
        }
    }
    for(auto i:arr){
        if(i == -1){
            cout<<-1<<endl;
            return;
        }
    }
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
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