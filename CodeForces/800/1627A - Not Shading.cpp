#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, r, c;
    cin>>n>>m>>r>>c;
    r--, c--;
    vector<vector<char>> arr(n, vector<char> (m));
    int countBlacks = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j] == 'B') countBlacks++;
        }
    }
    if(countBlacks == 0){
        cout<<-1<<endl;
        return;
    }else if(arr[r][c] == 'B'){
        cout<<0<<endl;
        return;
    }else{
        // same row check
        for(int i=0;i<m;i++){
            if(i != c && arr[r][i] == 'B'){
                cout<<1<<endl;
                return;
            }
        }
        for(int i=0;i<n;i++){
            if(i != r && arr[i][c] == 'B'){
                cout<<1<<endl;
                return;
            }
        }
        cout<<2<<endl;
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