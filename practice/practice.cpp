class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> mp, mp1;
        for(auto ch:p) mp[ch]++;
        int st = -1, en = -1;
        int match = 0;
        while(true){
            bool f1 = false, f2 = false;
            while(en < (int)(s.length()-1) and match < p.length()){
                en++;
                char ch = s[en];
                mp1[ch]++;
                f1 = true;
                if(mp.find(ch) != mp.end() and mp1[ch] <= mp[ch]){
                    match++;
                }
                if(match == p.length()) break;
            }
            while(st < en and match == p.length()){
                ans.push_back(st+1);
                st++;
                char ch = s[st];
                mp1[ch]--;
                f2 = true;
                if(mp.find(ch) != mp.end() and mp1[ch] < mp[ch]){
                    match--;
                }                
            }
            
            if(!f1 and !f2) break;
        }
        return ans;
    }
};