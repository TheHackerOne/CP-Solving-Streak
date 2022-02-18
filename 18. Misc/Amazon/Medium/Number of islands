class Solution {
private:
   void dfs(vector<vector<char>> &grid, int i, int j){
      int row = grid.size(), col = grid[0].size();
      grid[i][j] = '0';
      if(i-1 >= 0 and grid[i-1][j] == '1') dfs(grid, i-1, j);
      if(j+1 < col and grid[i][j+1] == '1') dfs(grid, i, j+1);
      if(i+1 < row and grid[i+1][j] == '1') dfs(grid, i+1, j);
      if(j-1 >= 0 and grid[i][j-1] == '1') dfs(grid, i, j-1);
   }

public:

    int numIslands(vector<vector<char>>& grid) {
         int row = grid.size(), col = grid[0].size();
         int components = 0;
        for(int i=0;i<row;i++){
         for(int j=0;j<col;j++){
            if(grid[i][j] == '1'){
               components++;
               dfs(grid, i, j);
            }
         }
        }

        return components;
    }
};