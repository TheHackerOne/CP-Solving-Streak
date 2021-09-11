int countOccurence(int arr[], int n, int k) {
    // Your code here
    int ratio = n / k;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }
    int count = 0;
    for (auto i : mp) {
        if (i.second > ratio)
            count++;
    }
    return count;
}