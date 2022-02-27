class Solution {
private:
    unordered_map<string, int> mp;
    int recur(string str){
        // base case
        if(str.length() == 0 ) return 1;
        if(str[0] == '0') return 0;
        
        // memo
        if(mp.find(str) != mp.end()) return mp[str];
        
        // main logic
        int ans = 0;
        ans += recur(str.substr(1));
        if(str.length() >= 2 and str.substr(0, 2) <= "26"){
            ans += recur(str.substr(2));
        }
        return mp[str] = ans;
    }
public:
    int numDecodings(string s) {
        mp.clear();
        return recur(s);
    }
};