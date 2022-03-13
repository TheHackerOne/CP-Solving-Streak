class Solution {
private:
    int dp[12][10005];
    long recur(int idx, int n, int amount, vector<int> &coins){
        // base case
        if(idx == n){
            if(amount == 0) return 0;
            else return INT_MAX;
        }
        
        //memo
        if(dp[idx][amount] != -1 ) return dp[idx][amount];
        
        // main logic
        long ans = INT_MAX;
        // select coin
        if(amount >= coins[idx])
            ans = min(ans, recur(idx, n, amount-coins[idx], coins)+1);
            
        // reject coin
        ans = min(ans, recur(idx+1, n, amount, coins));
        return dp[idx][amount] = ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int n = coins.size();
        int ans = recur(0, n, amount, coins);
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};