#include<bits/stdc++.h>
using namespace std;

void solve() {
    string str;
    cin>>str;
    sort(str.begin(), str.end());
    cout<<str<<endl;
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