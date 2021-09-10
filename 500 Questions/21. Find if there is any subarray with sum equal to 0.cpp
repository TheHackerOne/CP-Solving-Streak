bool subArrayExists(int arr[], int n)
{
	vector<int> prefixSum;
	for (int i = 0; i < n; i++) {
		if (i == 0)
			prefixSum.push_back(arr[i]);
		else prefixSum.push_back(arr[i] + prefixSum[i - 1]);
	}
	unordered_map<int, int> mp;
	mp[0] = 1;
	for (int i = 0; i < n; i++) {
		mp[prefixSum[i]]++;
	}
	for (auto i : mp) {
		if (i.second > 1) return true;
	}
	return false;
}