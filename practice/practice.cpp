class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long n = questions.size();
        vector<long long> dp(n+1, 0);
        dp[0] = 0, dp[1] = questions[0][0];
        for(long long i=2;i<=n;i++){
            long long idx = i-1;
            long long op1 = dp[i-1];
            long long op2 = questions[idx][0] + i-questions[idx][1]-1>=0?dp[i-questions[idx][1]-1]:INT_MIN;
            dp[i] = max(op1, op2);
        }
        return dp[n];
    }
};