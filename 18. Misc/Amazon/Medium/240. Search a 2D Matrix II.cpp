class Solution {
public:
   bool isValid(int r, int c, vector<vector<int>> &matrix){
      int row = matrix.size(), col = matrix[0].size();
      if(r >= 0 and r < row and c >= 0 and c < col) return true;
      else return false;
   }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        
        int r = 0, c = col-1;
        while(isValid(r, c, matrix) and matrix[r][c] != target){
            int num = matrix[r][c];
            if(num == target) break;
            else if(target > num) r++;
            else c--;
        }
        if(!isValid(r, c, matrix)) return false;
        return true;
    }
};