#include<bits/stdc++.h>
using namespace std;

const int N=2005;
int dp[N][2];
bool che(int a, int b) {
    if (a == 0) return false;
    if (dp[a][b] != -1)
        return dp[a][b];
    bool ans = false;
    if (a>= 1) ans |= !che(a - 1, !b);
    if (a>= 2) ans |= !che(a - 2, !b);
    return dp[a][b] = ans;
}

void solve(){

    int n, cnt = 0;
    string s; cin >> n >> s;
    for(int i=0;i<n+1;i++) dp[i][0] = dp[i][1] = -1;
    for(int i=0;i<n;i++) cnt += (s[i] == s[i + 1]);
    cout<<(che(cnt, 0) ? "JJ" : "Uttu")<<endl;
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