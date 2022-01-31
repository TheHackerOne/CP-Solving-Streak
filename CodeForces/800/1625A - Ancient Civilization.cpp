#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, l;
    cin>>n>>l;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> a(32);
    for(int i=0;i<31;i++){
        int zero = 0, one = 0;
        for(int j=0;j<n;j++){
            int num = arr[j];   
            int ithBitNum = num>>i;
            if(ithBitNum&1) one++;
            else zero++;
        }   
        if(one > zero){
            a[i] = 1;
        }else a[i] = 0;
    }
    int num = 0, power = 0;
    for(int i=0;i<31;i++){
        if(a[i] == 1){
            num += pow(2, i);
        }    
    }
    cout<<num<<endl;
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