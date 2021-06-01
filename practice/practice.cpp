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

    void bfs(vector<int> adjList[], int src, int *visited) {
        queue<int> q;
        q.push(src);
        visited[src] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int child : adjList[curr]) {
                if (!visited[child]) {
                    visited[child] = 1;
                    q.push(child);
                }
            }
        }
    }

    int connectedComponents(vector<int> adjList[], int V) {
        int visited[V] = {0};
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                bfs(adjList, i, visited);
                count++;
            }
        }
        return count;
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
    obj.printGraph(adjList, V);
    cout << "No of connected Components - " << obj.connectedComponents(adjList, V);

    return 0;
}