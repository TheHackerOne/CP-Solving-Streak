class Solution {
public:
    int parent[900];
    
    void find(int a){
        if(parent[a] < 0 ) return a;
        return parent[a] = find(parent[a]);
    }
    
    void unionFunc(int a, int b, int &count){
        int a = parent(a);
        int b = parent(b);
        if(a == b) count++;
        else if(parent[a] < parent[b]){
            parent[a] += parent[b];
            parent[b] = a;
        }else{
            parent[b] += parent[a];
            parent[a] = b;
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int count = 1, gridLen = grid.size(), dots = gridLen+1;
        memset(parent, -1, sizeof(parent));
        
        for(int i=0;i<dots;i++){
            for(int j=0;j<dots;j++){
                int cellNo = i*dots+j;
                if(cellNo != 0)
                    unionFunc(0, cellNo, count);
            }
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].length();j++){
                if(grid[i][j] == '/'){
                    int cellNo1 = i*dots+j+1;
                    int cellNo2 = (i+1)*dots+j;
                    unionFunc(cellNo1, cellNo2);
                }else if(grid[i][j] == '\\'){
                    int cellNo1 = i*dots+j;
                    int cellNo2 = (i+1)*dots+(j+1);
                    unionFunc(cellNo1, cellNo2);
                }
            }
        }
        
        return count;
    }
};