#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    return a > b;
}

long long pow(int n, int p){
    if(p == 0) return 1;
    if(p == 1) return n;

    int res = pow(n, p/2);
    if(p%2 == 0) return res*res;
    else return res*res*n;
}

void solve() {
    long long n;
    cin>>n;
    vector<long long> arr(n);
    long long ones = 0,zeros = 0;
    for(long long i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i] == 0) zeros++;
        else if(arr[i] == 1) ones++;
    }
    long long ans = ones*pow(2, zeros);
    cout<<ans<<endl;

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