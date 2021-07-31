#include<bits/stdc++.h>
using namespace std;

#define ll long long

// int matrix[1001][1001];
// int dist[1001][1001];

// bool isValid(int cr, int cc) {
// 	return (cr > 1000 || cc > 1000 || cr <= 0 || cc <= 0 || matrix[cr][cc] == -1 || matrix[cr][cc] == 1) ? false : true;
// }

// int BFS(int srcR, int srcC, int desR, int desC) {
// 	queue<pair<int, pair<int, int>>> q;
// 	matrix[srcR][srcC] = 1;
// 	q.push({0, {srcR, srcC}});

// 	vector<int> cordX = { -1, 1, 0, 0};
// 	vector<int> cordY = {0, 0, 1, -1};

// 	while (!q.empty()) {
// 		int size = q.size();
// 		while (size--) {
// 			pair<int, pair<int, int>> curr = q.front();
// 			q.pop();
// 			int currDist = curr.first;
// 			int currR = curr.second.first;
// 			int currC = curr.second.second;
// 			for (int i = 0; i < 4; i++) {
// 				int nR = currR + cordX[i] , nC = currC + cordY[i];
// 				if (isValid(nR, nC)) {
// 					matrix[nR][nC] = 1;
// 					dist[nR][nC] = currDist + 1;
// 					q.push({dist[nR][nC], {nR, nC}});
// 					if (nR == desR && nC == desC) break;
// 				}
// 			}
// 		}
// 	}
// 	return dist[desR][desC];
// }

// int main() {
// 	long long t;
// 	cin >> t;
// 	while (t--) {
// 		memset(matrix, 0, sizeof(matrix));
// 		memset(dist, 0, sizeof(dist));
// 		int ar, ac, br, bc, fr, fc;
// 		cin >> ac >> ar;
// 		cin >> bc >> br ;
// 		cin >> fc >> fr;

// 		matrix[fr][fc] = -1;

// 		int ans = BFS(ar, ac, br, bc);
// 		cout << ans << endl;
// 	}

// 	return 0;
// }

int main() {
	long long t;
	cin >> t;
	while (t--) {
		// memset(matrix, 0, sizeof(matrix));
		// memset(dist, 0, sizeof(dist));
		int ar, ac, br, bc, fr, fc;
		cin >> ac >> ar;
		cin >> bc >> br ;
		cin >> fc >> fr;

		if (ar == br) {
			if ((fr == ar) && ((fc > ac && fc < bc) || (fc > bc && fc < ac)) ) {
				cout << abs(ar - br) + abs(ac - bc) + 2 << endl;
			} else {
				cout << abs(ar - br) + abs(ac - bc) << endl;
			}
		} else if (ac == bc) {
			if ((fc == ac) && ((fr > ar && fr < br) || (fr > br && fr < ar))) {
				cout << abs(ar - br) + abs(ac - bc) + 2 << endl;
			} else {
				cout << abs(ar - br) + abs(ac - bc) << endl;
			}
		} else {
			cout << abs(ar - br) + abs(ac - bc) << endl;
		}
	}

	return 0;
}