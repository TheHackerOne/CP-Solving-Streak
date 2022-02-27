class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int minCost = 0;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i == 0 and j == 0) dp[i][j] = grid[i][j];
                else{
                    int op1 = i-1>=0 ? dp[i-1][j] : INT_MAX;
                    int op2 = j-1>=0 ? dp[i][j-1] : INT_MAX;
                    dp[i][j] = min(op1,op2)+grid[i][j];
                }
            }
        }
        return dp[row-1][col-1];
    }
};