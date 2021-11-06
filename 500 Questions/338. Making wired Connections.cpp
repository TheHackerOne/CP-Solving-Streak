class Solution {
public:
    void dfs(vector<int> g[], int src, vector<int> &vis){
        vis[src] = 1;
        for(int child:g[src]){
            if(!vis[child]){
                dfs(g, child, vis);
            }
        }
    }
    
    int connectedComponents(vector<int> g[], int nodes, int edges){
        int count = 0;
        vector<int> vis(nodes, 0);
        for(int i=0;i<nodes;i++){
            if(!vis[i]){
                count++;
                dfs(g, i, vis);
            }
        }
        return count;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> g[n];
        int nodes = n, edges = connections.size();
        if(edges < nodes-1) return -1;
        for(int i=0;i<connections.size();i++){
            vector<int> edge = connections[i];
            int a = edge[0], b = edge[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        int noOfConnectedComponents = connectedComponents(g, n, connections.size());
        return noOfConnectedComponents-1;
    }
};