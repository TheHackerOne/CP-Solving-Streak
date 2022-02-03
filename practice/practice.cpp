#include<bits/stdc++.h>
using namespace std;

void dijikstra(int src, int v, unordered_map<int, vector<pair<int, int>>> &graph){ 
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
    pq.push({ 0, src });
    vector<bool> visited(v, 0);
    // remove mark* work add*
    while(!pq.empty()){
        // remove
        pair<int, int> p = pq.top();
        pq.pop();
        int node = p.second;
        int distTillNow = p.first;
        // mark
        if(visited[node]) continue;
        visited[node] = 1;
        // work
        cout<<src<<" -> "<<node<<" @ "<<distTillNow<<endl;
        // add neighbours
        for(auto i:graph[node]){
            if(!visited[i.first] && distTillNow+i.second < dist[i.first]){
                dist[i.first] = distTillNow+i.second;
                pq.push({ dist[i.first], i.first });
            }
        }
    }
}

void prims(int src, int v, unordered_map<int, vector<pair<int,int>>> graph){
    vector<bool> visited(v, 0);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0, { src, src } });
    while(!pq.empty()){
        // remove
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int parent = p.second.first;
        int node = p.second.second;
        int cost = p.first;
        // mark
        if(visited[node]) continue;
        visited[node] = 1;
        // work
        cout<<parent<<" -> "<<node<<" @ "<<cost<<endl;
        // add neighbour
        for(auto neigh:graph[node]){
            if(!visited[neigh.first]){
                pq.push({ neigh.second, { node, neigh.first }});
            }
        }
    }
}

bool comp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){
    return a.first < b.first;
}

vector<int> parent(10000, -1);

int findParent(int node){
    if(parent[node] < 0) return node;

    return findParent(parent[node]);
}

void unionNodes(int a, int b, int w){
    int oa = a, ob = b;
    a = findParent(a);
    b = findParent(b);
    if(a != b){
        cout<<oa<<" -> "<<ob<<" @ "<<w<<endl;
        if(a < b){
            parent[a] += parent[b];
            parent[b] = a;
        }else{
            parent[b] += parent[a];
            parent[a] = b;
        }
    }
}

void kruskal(int src, unordered_map<int, vector<pair<int, int>>> &graph){
    vector<pair<int, pair<int, int>>> arr;
    for(auto i:graph){
        int node = i.first;
        vector<pair<int, int>> neigh = i.second;
        for(auto j:neigh){
            arr.push_back({ j.second, { node, j.first } });
        }
    }

    sort(arr.begin(), arr.end(), comp);

    for(int i=0;i<arr.size();i++){
        int u = arr[i].second.first, v = arr[i].second.second, w = arr[i].first;
        unionNodes(u, v, w);
    }
}

void bellmanFord(int src, int v, unordered_map<int,vector<pair<int, int>>> &graph){
    vector<int>dist(v, INT_MAX);

    dist[src] = 0;

    for(int i=0;i<v-1;i++){
        for(auto i:graph){
            int u = i.first;
            vector<pair<int, int>> neigh = i.second;
            for(auto j:neigh){
                int weight = j.second, v = j.first;
                if(dist[u] == INT_MAX) continue;
                if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u]+weight;
                }
            }
        }
    }
    for(auto i:dist)cout<<i<<" ";
}

int main() {
#ifndef ONLINE_JUDGE  
    freopen("Error.txt", "w", stderr);
#endif

    int v, e;
    cin>>v>>e;
    unordered_map<int, vector<pair<int, int>>> graph;
    for(int i=0;i<e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    // single source shortest path in terms of edge weight
    cout<<"DIJIKSTRA\n";
    dijikstra(0, v, graph);
    cout<<endl;

    // minimum spanning tree
    cout<<"PRIMS \n";
    prims(0, v, graph);
    cout<<endl;

    // KRUSKAL minimum spanning tree
    cout<<"Kruskal\n";
    kruskal(0, graph);
    cout<<endl;

    // bellman ford - shortest path in weighted graph with negative edge weight(not negative weight cycle)
    bellmanFord(0, v, graph);


    return 0;
}