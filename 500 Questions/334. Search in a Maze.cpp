class Solution{
    public:
    vector<int> x =  {+1, 0, 0, -1}; 
    vector<int> y = {0, -1, 1, 0};
    
    int startX = 0, startY = 0, finishX, finishY;
    
    void solveMaze(vector<vector<int>> &m, vector<string> &ans, int sX, int sY, string s, vector<vector<int>> &vis, int n){
        if(sX == finishX && sY == finishY){
                ans.push_back(s);
                return;
        } 
        string dir = "DLRU"; 
        
        for(int i=0;i<4;i++){
            int newX = sX+x[i], newY = sY+y[i];
            if(newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
            if(m[newX][newY] != 0 && !vis[newX][newY]){
                vis[newX][newY] = 1;
                solveMaze(m, ans, newX, newY, s+dir[i], vis, n);
                vis[newX][newY] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<string> ans;
        finishX = n-1, finishY = n-1;
        string s = "";
        vis[0][0] = 1;
        
        if(m[0][0] == 1)solveMaze(m, ans, startX, startY, s, vis, n);
        
        return ans;
    }
};