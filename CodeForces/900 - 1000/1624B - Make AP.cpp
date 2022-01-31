#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a,b, c;
    cin>>a>>b>>c;
    // 1st possibility
    int num1 = 2*b-a;
    int den1 = c;
    if(num1!=0 && num1%den1 == 0) {
        if(num1/den1 > 0){
            cout<<"YES"<<endl;
            return;
        }
    }
    // 2nd possibility
    int num2 = c+a;
    int den2 = 2*b;
    if(num2!=0 && num2%den2 == 0) {
        if(num2/den2 > 0){
            cout<<"YES"<<endl;
            return;
        }
    }
    // 3rd possibility
    int num3 = 2*b-c;
    int den3 = a;
    if(num3 != 0 && num3%den3 == 0){
        if(num3/den3 > 0){
            cout<<"YES"<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
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