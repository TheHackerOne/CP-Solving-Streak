class Solution {
public:
    vector<int> r = {0, 0, 1, -1};
    vector<int> c = {1, -1, 0, 0};
    
    int rows;
    int columns;
    
    bool isValid(int sr, int sc){
        return (sr >= 0 && sr < rows && sc >= 0 && sr < columns);
    }
    
    void dfsFill(int sr, int sc, vector<vector<int>> &image, vector<vector<int>> &ffill, int newColor, int parentColor, vector<vector<int>> &vis){
        if(parentColor == -1){
            ffill[sr][sc] = newColor;
            parentColor = image[sr][sc];
        }else if(image[sr][sc] == parentColor){
            ffill[sr][sc] = newColor;
        }
        vis[sr][sc] = 1;
        for(int i=0;i<4;i++){
            int newR = sr + r[i], newC = sc + c[i];
            if(isValid(newR, newC) && image[newR][newC] == parentColor && (!vis[newR][newC])){
                dfsFill(newR, newC, image, ffill, newColor, image[sr][sc], vis);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        rows = image.size();
        columns = image[0].size();
        vector<vector<int>> floodfill = image;
        vector<vector<int>> vis(rows, vector<int> (columns, 0));
        
        dfsFill(sr, sc, image, floodfill, newColor, -1, vis);
        
        return floodfill;
    }
};