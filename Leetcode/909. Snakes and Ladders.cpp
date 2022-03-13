class Solution {
private:
	pair<int, int> findCoordinate(int curr, int n) {
        int r = n - (curr - 1) / n  - 1;
        int c = (curr - 1) % n;
        if (r % 2 == n % 2) {
            return {r, n - 1 - c};
        } else {
            return {r, c};
        }
    }

public:
	int snakesAndLadders(vector<vector<int>>& board) {
		queue<int> q;
		q.push(1);
		int steps = 0;
		int n = board.size();
		vector<vector<bool>> visited(n, vector<bool> (n, false));
        visited[n-1][0] = true;
		while(!q.empty()){
			int size = q.size();
			while(size--){
				int block = q.front();
				q.pop();
				if(block == n*n) return steps;
				for(int i=1;i<=6;i++){
					int blockNum = block + i;
					if(blockNum > n*n) break;
					pair<int, int> cord = findCoordinate(blockNum, n);
					int r = cord.first, c = cord.second;
					if(!visited[r][c] and board[r][c] == -1){
						visited[r][c] = 1;
						q.push(blockNum);
					}else if(!visited[r][c]){
                        visited[r][c] = 1;
                        q.push(board[r][c]);
                    }
				}
			}
            steps++;
		}
        return -1;
	}
};