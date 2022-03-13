class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.length();
        vector<vector<bool>> dp(n, vector<bool> (n, 0));
        string ans = "";
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                int len = j-i+1;
                if(g == 0) {
                    dp[i][j] = true;
                    if(len > ans.length()) ans = str.substr(i, len);
                }else if(g == 1){
                    if(str[i] == str[j]) dp[i][j] = true;
                    if(dp[i][j]) if(len > ans.length()) ans = str.substr(i, len);
                }else{
                    if(str[i] == str[j] and dp[i+1][j-1]){
                        dp[i][j] = true;
                    }
                    if(dp[i][j]) if(len > ans.length()) ans = str.substr(i, len);
                }
            }
        }
        return ans;
    }
};