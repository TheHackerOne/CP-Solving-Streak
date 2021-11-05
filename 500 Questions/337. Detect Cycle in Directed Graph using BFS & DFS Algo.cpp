#include<bits/stdc++.h>

using namespace std;

vector<int> topo;

bool toposort(vector<int> g[], int nodes, vector<bool> &visited){
    // calculate indegree
    vector<int> indegree(nodes, 0);
    for(int i=0;i<nodes;i++){
        for(int j:g[i]){
            indegree[j]++;
        }
    }

    queue<int> q;
    // all nodes with indegree 0
    for(int i=0;i<nodes;i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        topo.push_back(node);
        visited[node] = 1;
        q.pop();
        for(int neigh:g[node]){
            if(!visited[neigh]){
                q.push(neigh);
                visited[neigh] = 1;
            }
        }
    }

    if(topo.size() == nodes) return false;
    else return true;
}

bool cycleDetectionUsingBFS(vector<int> g[], int src, int nodes, vector<bool> &vis){
    // toposort using BFS
    bool hasCycle = toposort(g, nodes, vis);
    return hasCycle;
}

bool cycleDetectionUsingBFSHelper(vector<int> g[], int src, int nodes){
    vector<bool> visited(nodes, 0);
    bool isCyclePresent = false;
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            bool isCycle = cycleDetectionUsingBFS(g, i, nodes, visited);
            if(isCycle) {
                isCyclePresent = true;
                break;
            }
        }
    }
    return (isCyclePresent ? true : false);
}

bool cycleDetectionUsingDFS(vector<int> g[], int parent, int src, vector<bool> &vis, vector<bool> &DFSvis){
    vis[src] = 1;
    DFSvis[src] = 1;
    for(int neigh: g[src]){
        if(!DFSvis[neigh]){
            if(cycleDetectionUsingDFS(g, src, neigh, vis, DFSvis))
                return true;
        }else if(neigh != parent){
            return true;
        }
    }
    DFSvis[src] = 0;
    return false;
}

bool cycleDetectionUsingDFSHelper(vector<int> g[], int src, int nodes){
    vector<bool> visited(nodes, 0), DFSvisited(nodes, 0);
    bool isCyclePresent = false;
    for(int i=0;i<nodes;i++){
        if(!visited[nodes]){
            bool isCycle = cycleDetectionUsingDFS(g, -1, i, visited, DFSvisited);
            if(isCycle) {
                isCyclePresent = true;
                break;
            }
        }
    }
    return (isCyclePresent ? true : false);
}

int main(){
    int nodes, edges;
    cin>>nodes>>edges;
    vector<int> g[nodes];

    int a, b;
    for(int i=0;i<edges;i++){
        cin>>a>>b;
        g[a].push_back(b);
    }

    if(cycleDetectionUsingBFSHelper(g, 0, nodes)){
        cout<<"Cycle Present using BFS"<<endl;
    }else{
        cout<<"Cycle not present using BFS"<<endl;
    }
    if(cycleDetectionUsingDFSHelper(g, 0, nodes)){
        cout<<"Cycle present using DFS"<<endl;
    }else{
        cout<<"Cycle not present using DFS"<<endl;
    }

    return 0;
}