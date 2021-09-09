#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	int minprofit = prices[0], profit = INT_MIN;
	for (int i = 0; i < n; i++) {
		minprofit = min(minprofit, prices[i]);
		int prof = prices[i] - minprofit;
		profit = max(profit, prof);
	}
	return profit;
}
void solve() {
	int n;
	cin >> n;
	vector<int> prices(n);
	for (int i = 0; i < n; i++) {
		cin >> prices[i];
	}
	cout << maxProfit(prices) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}