#include<bits/stdc++.h>
using namespace std;

int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp;
        for(auto str:words1) mp[str]++;
        for(auto i:mp){
            if(i.second != 1) mp.erase(i.first);
        }
        // for(auto &str:words2) mp[str]++;
        // int ans = 0;
        // for(auto i:mp){
        //     if(i.second == 2) ans++;
        // }
        return 0;
    }

void solve() {
  vector<string> str1 = {"yash"};
  vector<string> str2 = {"yash"};
  cout<<countWords(str1, str2);
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