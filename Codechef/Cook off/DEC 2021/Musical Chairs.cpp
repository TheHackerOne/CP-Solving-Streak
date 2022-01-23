#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin>>n;
    int count = 0;
    n--;
    for(int i=1;i*i<=(n);i++){
        if((n)%i == 0)count += 2;
        if(i*i == n) count--;
    }
    cout<<count<<endl;
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