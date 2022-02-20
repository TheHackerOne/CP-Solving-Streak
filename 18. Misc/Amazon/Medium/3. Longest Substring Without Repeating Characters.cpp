class Solution {
public:
   bool isValid(unordered_map<char, int> &mp){
      for(auto i:mp){
         if(i.second > 1) return false;
      }
      return true;
   }

    int lengthOfLongestSubstring(string s) {
        int release = -1;

        unordered_map<char, int> mp;

        int ans = 0;

        for(int i=0;i<s.length();i++){
         mp[s[i]]++;
         while(!isValid(mp)){
            mp[s[++release]]--;
         }
         int cnt = i-release;

         ans = max(ans, cnt);
        }
        return ans;
    }
};