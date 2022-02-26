class Solution {
private:
    int countNeig(vector<vector<int>> &board, int r, int c){
        int row = board.size(), col = board[0].size(), cnt = 0;
        if(r-1 >= 0 and (board[r-1][c] == 1 or board[r-1][c] == 2)) cnt++;
        if(r-1 >= 0 and c+1 < col and (board[r-1][c+1] == 1 or board[r-1][c+1] == 2)) cnt++;
        if(c+1 < col and (board[r][c+1] == 1 or board[r][c+1] == 2)) cnt++;
        if(r+1 < row and c+1 < col and (board[r+1][c+1] == 1 or board[r+1][c+1] == 2)) cnt++;
        if(r+1 < row and (board[r+1][c] == 1 or board[r+1][c] == 2)) cnt++;
        if(r+1 < row and c-1 >= 0 and (board[r+1][c-1] == 1 or board[r+1][c-1] == 2)) cnt++;
        if(c-1 >= 0 and (board[r][c-1] == 1 or board[r][c-1] == 2)) cnt++;
        if(r-1 >= 0 and c-1 >= 0 and (board[r-1][c-1] == 1 or board[r-1][c-1] == 2)) cnt++;
        return cnt;
    }    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        // 1 --> 0 if count1 < 2 or count1 > 3, 2
        // 1 --> 1 if count1 >= 2 and <= 3
        // 0 --> 1 if count1 == 3, 3
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == 0 and countNeig(board, i, j) == 3){
                    board[i][j] = 3;
                }else if(board[i][j] == 1 and (countNeig(board, i, j) < 2 or countNeig(board, i, j) > 3)){
                    board[i][j] = 2;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == 2) board[i][j] = 0;
                else if(board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};