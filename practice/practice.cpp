#include<bits/stdc++.h>
using namespace std;

void Dijikstra(int src, int vertex, vector<pair<int, int>> graph[]){
    vector<int> visited(vertex, 0);
    vector<int> dist(vertex, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src]=0;
    while(!pq.empty()){
        // remove
        pair<int,int> p = pq.top();
        pq.pop();
        int node = p.second;
        int distance = p.first;

        // mark*
        if(visited[node]) continue;
        visited[node] = 1;

        // work


        // add*
        for(auto neigh:graph[node]){
            if(!visited[neigh.first] && distance+neigh.second < dist[neigh.first]){
                dist[neigh.first] = distance + neigh.second;
                pq.push({dist[neigh.first], neigh.first});
            }
        }
    }
    for(auto i:dist) cout<<i<<" ";
}

void Prims(int src, int vertex, vector<pair<int, int>> graph[]){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, { -1, src }}); // dist from parent to node, parent, node
    vector<int> visited(vertex, 0);
    int mstCost = 0;
    while(!pq.empty()){
        // remove
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int node = p.second.second;
        int parent = p.second.first;
        int dist = p.first;

        // mark*
        if(visited[node])continue;
        visited[node] = 1;

        // work
        cout<<parent<<" -> "<<node<<" @ "<<dist<<endl;
        mstCost += dist;
        // add*
        for(auto neigh:graph[node]){
            if(!visited[neigh.first]){
                pq.push({neigh.second, { node, neigh.first}});
            }
        }
    }
    cout<<"Cost of MST -> "<<mstCost<<endl;
}

vector<int> parent(10000, -1);

int findParent(int node){
    if(parent[node] < 0) return node;

    return findParent(parent[node]);
}

void unionNodes(int a,int b){
    a = findParent(a);
    b = findParent(b); 
    if(a < b){
        parent[a] += parent[b];
        parent[b] = a;
    }else{
        parent[b] += parent[a];
        parent[a] = b;
    }
}

void Kruskal(int src, int vertex,vector<pair<int, int>> graph[]){
    priority_queue<pair<int, pair<int, int>> ,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i=0;i<vertex;i++){
        for(auto j:graph[i]){
            pq.push({ j.second, {i, j.first} });
        }
    }
    int mstCost = 0;
    while(!pq.empty()){
        // remove
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int node = p.second.first;
        int parent = p.second.second;
        int cost = p.first;

        int a = findParent(node);
        int b = findParent(parent);
        if((a != b) || (a == -1 && b == -1)){
            unionNodes(node, parent);
            cout<<parent<<" "<<node<<endl;
            mstCost += cost;
        }
    }
    cout<<"Cost of MST -> "<<mstCost<<endl;
}

int main() {
    int vertex, edges;
    cin>>vertex>>edges;

    vector<pair<int, int>> graph[vertex];
    for(int i=0;i<edges;i++){
        int u, v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    cout<<"Dijikstra for shortest path from a source to all other vertex "<<endl;
    Dijikstra(0, vertex, graph);

    cout<<endl<<endl;

    cout<<"Prims for minimum spanning tree "<<endl;
    Prims(0, vertex, graph);

    cout<<endl<<endl;

    cout<<"Kruskal (Dijoint set Union) for MST"<<endl;
    Kruskal(0, vertex, graph);

    return 0;
}