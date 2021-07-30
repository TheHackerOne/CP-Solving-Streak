#include<bits/stdc++.h>
using namespace std;
bool comp ( pair<int, int>a, pair<int, int>b) {
	return a.second > b.second;
}
int main() {
	int N;
	cin >> N;
	unordered_map<int, int>ump;
	for (int i = 0; i < N; i++) {
		int item;
		cin >> item;
		ump[item]++;
	}

	vector<pair<int, int>>vec;

	for (auto x : ump)
		vec.push_back({x.first, x.second});

	sort(vec.begin(), vec.end(), comp);

	for (auto x : vec) {
		for (int i = 0; i < x.second; i++) {
			cout << x.first << " ";
		}
	}
}