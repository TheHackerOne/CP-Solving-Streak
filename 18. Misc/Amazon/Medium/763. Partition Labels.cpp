class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for(int i=0;i<s.length();i++){
         mp[s[i]] = i;
        }

        int maxRange = 0, st = 0;
        vector<int> ans;
        for(int i=0;i<s.length();i++){
         maxRange = max(maxRange, mp[s[i]]);
         if(i == maxRange){
            ans.push_back(i-st+1);
            st = i+1;
         }
        }

        return ans;
    }
};