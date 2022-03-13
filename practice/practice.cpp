#include<bits/stdc++.h>
using namespace std;

void solve() {

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


class Solution {
private:
    void helper(string s, string ipsf, int dots, vector<string> &res){
        //base case
        if(dots == 3){
            if(s.length() == 0 or stoi(s) > 255 or (s.length() > 1 and s[0] == '0')) return;
            else{
              res.push_back(ipsf+s);
              return;
            }
        }
        
        // main logic
        for(int i=1;i<=3;i++){
            string sub = s.substr(0, i);
            if(stoi(sub) > 255 or (sub.length() > 1 and sub[0] == '0')) continue;
            helper(s.substr(i), ipsf+sub+".", dots+1, res);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(s, "", 0, res);
        return res;
    }
};