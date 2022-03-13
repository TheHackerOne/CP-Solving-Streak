class Solution {
private:
	bool dfs(int node, unordered_map<int, vector<int>> &graph, vector<int> &visited,vector<int> &dfsVisited){
		visited[node] = 1;
		dfsVisited[node] = 1;
		for(auto neigh:graph[node]){
			if(!visited[neigh]){
				bool isCycle = dfs(neigh, graph, visited, dfsVisited);
                if(isCycle) return true;
			}else{
                if(dfsVisited[neigh]) return true;
            }
		}
		dfsVisited[node] = 0;
        return false;
	}
	
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, vector<int>> graph;
		for(auto i:prerequisites){
			int u = i[0], v = i[1];
			graph[u].push_back(v);
		}

		// cycle detection
		vector<int> visited(numCourses, 0);
		vector<int> dfsVisited(numCourses, 0);
		for(auto i:graph){
			if(!visited[i.first]){
				bool isCycle = dfs(i.first, graph, visited, dfsVisited);
                if(isCycle) return false;
			}
		}
        return true;
	}
};