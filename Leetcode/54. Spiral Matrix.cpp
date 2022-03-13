class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int cnt = row*col;
        vector<int> ans;
        int minr = 0, minc = 0, maxr = row-1, maxc = col-1;
        while(cnt > 0){
            // row constant
            for(int c=minc;c<=maxc and cnt > 0 ;c++){
                ans.push_back(matrix[minr][c]);
                cnt--;
            }
            minr++;
            // col constant
            for(int r=minr;r<=maxr and cnt > 0;r++){
                ans.push_back(matrix[r][maxc]);
                cnt--;
            }
            maxc--;
            //row constant
            for(int c=maxc;c>=minc and cnt > 0;c--){
                ans.push_back(matrix[maxr][c]);
                cnt--;
            }
            maxr--;
            // col constant
            for(int r=maxr;r>=minr and cnt > 0;r--){
                ans.push_back(matrix[r][minc]);
                cnt--;
            }
            minc++;
        }
        return ans;
    }
};