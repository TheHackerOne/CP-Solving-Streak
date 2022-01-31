#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    n--;
    if(n&1){
        cout<<2<<" "<<n-2<<" "<<1<<endl;
    }else{
        if(n%4 == 0){
            cout<<n/2-1<<" "<<n/2+1<<" "<<1<<endl;
        }else{
            cout<<n/2-2<<" "<<n/2+2<<" "<<1<<endl;
        }
    }
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