class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        int time = -1;

        queue<pair<int, int>> q;

        vector<vector<int>> visited(row, vector<int>(col, 0));

        int rotten = 0, fresh = 0;

        for(int i=0;i<row;i++){
         for(int j=0;j<col;j++){
            if(grid[i][j] == 1) fresh++;
            if(grid[i][j] == 2){
               rotten++;
               q.push({ i, j });
               visited[i][j] = 1;
            }
         }
        }

        if(fresh == 0 and rotten == 0) return 0;
        if(rotten == 0) return -1;
        if(fresh == 0) return 0;

        while(!q.empty()){
         int size = q.size();
         while(size--){
            pair<int, int> orangeCordinate = q.front();
            int x = orangeCordinate.first;
            int y = orangeCordinate.second;
            q.pop();
            if(x-1 >= 0 and !visited[x-1][y] and grid[x-1][y] == 1){
               visited[x-1][y] = 1;
               q.push({ x-1, y });
            }
            if(y+1 < col and !visited[x][y+1] and grid[x][y+1] == 1){
               visited[x][y+1] = 1;
               q.push({ x,y+1 });
            }
            if(x+1 < row and !visited[x+1][y] and grid[x+1][y] == 1){
               visited[x+1][y] = 1;
               q.push({ x+1, y });
            }
            if(y-1 >= 0 and !visited[x][y-1] and grid[x][y-1] == 1){
               visited[x][y-1] = 1;
               q.push({ x, y-1 });
            }
         }
         time++;
        }

        for(int i=0;i<row;i++){
         for(int j=0;j<col;j++){
            if(grid[i][j] == 1 and visited[i][j] == false){
               return -1;
            }
         }
        }

        return time;
    }
};