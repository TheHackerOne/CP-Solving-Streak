#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    return a > b;
}

void solve() {
    long long int n;
    cin>>n;
    string str = to_string(n);
    int len = str.length();
    int x, y;
    bool flag=false;
    vector<int> an;
    for(int i=len-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            int ch1 = str[i]-'0', ch2 = str[j]-'0';
            int num = ch2*10+ch1;
            if(num%25 == 0){
                x = j, y = i;
                an.push_back(len-x-2);
            }
        }
    }
    sort(an.begin(), an.end());
    cout<<an[0]<<endl;
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