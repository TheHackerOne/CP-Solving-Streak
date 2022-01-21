#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n = 8, num = 0, bit = 0;
    while(n!=0){
        if((n&1)== 0)
            num = num^(1<<bit);
        cout<<"num -> "<<num<<endl;
        n >>= 1;
        bit++;
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