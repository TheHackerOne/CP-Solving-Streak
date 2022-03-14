#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin>>n>>m;
  vector<int> a(n), b(m);
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<m;i++)cin>>b[i];

  vector<pair<int, int>> arr;
  for(int i=0;i<n;i++){
    arr.push_back({ a[i], 1 });
  }

  for(int i=0;i<m;i++){
    arr.push_back({ b[i], 2 });
  }

  sort(arr.begin(), arr.end());

  int cnt = 0;

  for(int i=1;i<arr.size();i++){
    if(arr[i].second != arr[i-1].second){
      cnt++;
    }
  }

  cout<<cnt<<endl;
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