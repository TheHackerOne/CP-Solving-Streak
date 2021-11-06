#include<bits/stdc++.h>

using namespace std;
bool visited[100];

void bfs(vector<int> g[], int src, int nodes){
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<endl;
        for(int i:g[node]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main(){
    int nodes, edges;
    cin>>nodes>>edges;

    vector<int> g[nodes];

    for(int i=0;i<edges;i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    bfs(g, 4, nodes);

    return 0;
}