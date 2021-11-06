#include<bits/stdc++.h>

using namespace std;

bool visited[100];

void dfs(vector<int> g[], int src){
    visited[src] = 1;
    cout<<src<<endl;
    for(int neigh: g[src]){
        if(!visited[neigh])
            dfs(g, neigh);
    }
}

int main(){
    int nodes, edges;
    cin>>nodes>>edges;
    
    vector<int> g[nodes];
    
    int a, b;
    for(int i=0;i<edges;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    dfs(g, 0);
    
    return 0;
}