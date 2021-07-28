#include<bits/stdc++.h>
using namespace std;

int maximumSumSubarray(int K, vector<int> &Arr , int N) {
    int i = 0, j = 0, sum = 0, maxSum = INT_MIN;
    while (j < N) {

        sum += Arr[j];

        int elementCount = j - i + 1;

        if (elementCount < K)  j++;
        else if (elementCount == K) {
            maxSum = max(maxSum, sum);
            sum -= Arr[i];
            i++;
            j++;
        }
    }
    return maxSum;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);

    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << maximumSumSubarray(k, arr, n);

    return 0;
}