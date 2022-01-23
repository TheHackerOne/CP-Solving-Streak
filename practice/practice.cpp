class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, int rows, int cols){
        grid[row][col] = 0;
        int count = 0;
        if(col-1 >= 0 && grid[row][col] != 0) count+=dfs(row, col-1,grid, rows, cols);
        if(row-1 >= 0 && grid[row][col] != 0) count+=dfs(row-1, col,grid, rows, cols);
        if(col+1 < cols && grid[row][col] != 0) count+=dfs(row, col+1,grid, rows, cols);
        if(row+1 < rows && grid[row][col] != 0) count+=dfs(row+1, col,grid, rows, cols);
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = INT_MIN;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] != 0){
                    ans = max(ans, dfs(i, j, grid, rows,cols));
                }
            }
        }
        return ans;
    }
};