#include<bits/stdc++.h>

using namespace std;

bool cycleDetectionUsingDFS(vector<int> g[], int src, int parent, int nodes, vector<bool> &vis){
    vis[src] = 1;
    for(int i:g[src]){
        if(!vis[i]){
            if(cycleDetectionUsingDFS(g, i, src, nodes, vis)){
                return true;
            }
        }else if(i != parent){
            return true;
        }
    }
    return false;
}

bool cycleDetectionUsingDFSHelper(vector<int> g[], int nodes){
    vector<bool> visited(nodes, 0);
    bool cyclePresent = false;
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            bool ans = cycleDetectionUsingDFS(g, i, -1, nodes, visited);
            if(ans){
                cyclePresent = true;
                break;
            }
        }
    }
    return ( cyclePresent ? true : false );
}

bool cycleDetectionUsingBFS(vector<int> g[], int nodes,int src, vector<bool> &vis){
    queue<int> q;
    vector<int> parent(nodes, -1);
    q.push(src);
    vis[src] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int neigh:g[node]){
            if(!vis[neigh]){
                q.push(neigh);
                vis[neigh] = 1;
                parent[neigh] = node;
            }else if(neigh != parent[node]){
                return true;
            }
        }
    }
    return false;
}

bool cycleDetectionUsingBFSHelper(vector<int> g[], int nodes){
    vector<bool> visited(nodes, 0);
    bool cyclePresent = false;
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            bool ans = cycleDetectionUsingBFS(g, nodes, i, visited);
            if(ans){
                cyclePresent = true;
                break;
            }
        }
    }
    return ( cyclePresent ? true : false );
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
    
    if(cycleDetectionUsingDFSHelper(g, nodes)){
        cout<<"Cycle is present using DFS"<<endl;
    }else{
        cout<<"Cycle is not present using DFS"<<endl;
    }
    
    if(cycleDetectionUsingBFSHelper(g, nodes)){
        cout<<"Cycle is present using BFS"<<endl;
    }else{
        cout<<"Cycle is not present using BFS"<<endl;
    }
    
    return 0;
}