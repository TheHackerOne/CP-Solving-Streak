#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
	int a1 = a[0], a2 = a[1], b1 = b[0], b2 = b[1];
	if (a1 != b1) {
		return a1 < b1;
	} else return a2 < b2;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> ans;
	sort(intervals.begin(), intervals.end());
	int start = intervals[0][0], end = intervals[0][0];
	for (int i = 0; i < intervals.size(); i++) {
		int s = intervals[i][0], e = intervals[i][1];
		if (s >= start && s <= end) {
			end = max(end, e);
		} else if (s > end) {
			vector<int> a;
			a.push_back(start);
			a.push_back(end);
			ans.push_back(a);
			start = s;
			end = e;
		}
	}
	vector<int> a;
	a.push_back(start);
	a.push_back(end);
	ans.push_back(a);
	return ans;
}


int main() {
	int n;
	cin >> n;
	vector<vector<int>> a;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		vector<int> s;
		s.push_back(x);
		s.push_back(y);
		a.push_back(s);
	}
	vector<vector<int>> ans = merge(a);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i][0] << " " << ans[i][1];
		cout << endl;
	}

	return 0;
}