#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    void printGraph(vector<int> adjList[], int V) {
        for (int i = 0; i < V; i++) {
            cout << i << " : ";
            for (int j : adjList[i])
                cout << j << " ";
            cout << endl;
        }
    }

    bool dfs(vector<int> adjList[], int src, int *col, int color, int *visited) {
        visited[src] = 1;
        col[src] = color;
        for (int child : adjList[src]) {
            if (!visited[child]) {
                if (!dfs(adjList, child, col, !color, visited))
                    return false;
            } else if (col[child] == color) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<int> adjList[], int *visited, int V) {
        int color[V];
        memset(color, -1, sizeof color);
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                if (dfs(adjList, i, color, 0, visited))
                    return true;
        }
        return false;
    }


};

int main() {
    int V, E;
    cin >> V >> E;
    vector<int> adjList[V];
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    Solution obj;
    int visited[V] = {0};
    obj.printGraph(adjList, V);
    if (obj.isBipartite(adjList, visited, V))
        cout << "Graph is Bipartite";
    else
        cout << "Graph is not Bipartite";


    return 0;
}