class Solution {
public:
    string fractionToDecimal(int num, int den) {
        string ans = "";
        long long pnum = num, pden = den;
        num = abs(num), den = abs(den);
          long long q = num/den;
          long long r = num%den;
          ans += to_string(q);
          long long beforeDec = ans.length();
          if(r == 0){
            return ans;
          }else{
            ans += ".";
            long long breakIdx = -1;
            unordered_map<long long, string> mp;
            while(r != 0){
              if(mp.find(r) != mp.end()){
                ans = mp[r]+'(' + ans.substr(mp[r].length()) + ')';
                break;
              }
              mp[r] = ans;
              r *= 10;
              q = r/den;
              r = r%den;
              ans += to_string(q);
            }
          }
          if((pnum < 0 and pden >= 0 ) or (pnum >= 0 and pden < 0)) ans = "-"+ans;
          return ans;
    }
};