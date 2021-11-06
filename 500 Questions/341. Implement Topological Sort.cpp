#include<bits/stdc++.h>

using namespace std;

vector<int> topoDFS, topoBFS;

void toposortDFSHelper(vector<int> g[], int src, vector<int> &vis){
    vis[src] = 1;
    for(int child:g[src]){
        if(!vis[child]){
            toposortDFSHelper(g, child, vis);
        }
    }
    topoDFS.push_back(src);
}

void toposortDFS(vector<int> g[], int nodes){
    vector<int> vis(nodes, 0);
    for(int i=0;i<nodes;i++){
        if(!vis[i]){
            toposortDFSHelper(g, i, vis);
        }
    }
}


void toposortBFS(vector<int> g[], int nodes){
    // calculate indegree
    vector<int> indegree(nodes, 0);
    for(int i=0;i<nodes;i++){
        for(int j:g[i]){
            indegree[j]++;
        }
    }

    // get nodes with indegree 0
    queue<int> q;
    for(int i=0;i<nodes;i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    // main logic
    while(!q.empty()){
        int node = q.front();
        topoBFS.push_back(node);
        q.pop();
        for(int child:g[node]){
            indegree[child]--;
            if(indegree[child] == 0)
                q.push(child);
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
    }

    toposortDFS(g, nodes);
    reverse(topoDFS.begin(), topoDFS.end());
    cout<<"TOPOSORT USING DFS"<<endl;
    for(int i=0;i<topoDFS.size();i++){
        cout<<topoDFS[i]<<" ";
    }
	cout<<endl;

    toposortBFS(g, nodes);
    cout<<"TOPOSORT USING BFS"<<endl;
    for(int i=0;i<nodes;i++){
        cout<<topoBFS[i]<<" ";
    }


    return 0;
}