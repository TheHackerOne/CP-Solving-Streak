class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp, mp1;
        int size = p.length();
        for(int i=0;i<p.length();i++){
            mp[p[i]]++;
        }
        for(int i=0;i<p.length()-1;i++){
            mp1[s[i]]++;
        }
        int st = 0;
        vector<int> ans;
        for(int en=p.length()-1;en<s.length();en++){
            mp1[s[en]]++;
            if(mp1 == mp){
                ans.push_back(st);
            }
            mp1[s[st]]--;
            if(mp1[s[st]] == 0) mp1.erase(s[st]);
            st++;
        }
        return ans;
    }
};