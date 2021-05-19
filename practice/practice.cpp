#include<bits/stdc++.h>
using namespace std;


int minNumberOfCoins1(int *arr, int size, int sum) {
    if (sum == 0) return 0;
    if (size == 0) return INT_MAX;

    if (arr[size - 1] <= sum) {
        return min(minNumberOfCoins1(arr, size - 1, sum), 1 + minNumberOfCoins1(arr, size, sum - arr[size - 1]));
    }
    else {
        return minNumberOfCoins1(arr, size - 1, sum);
    }
}

int minNumberOfCoins(int *arr, int size, int sum) {
    if (sum == 0) return 0;
    if (size == 0) return INT_MAX;

    if (arr[size - 1] <= sum) {
        int res1 = minNumberOfCoins(arr, size - 1, sum);
        int res2 = minNumberOfCoins(arr, size, sum - arr[size - 1]);
        return min(res1, 1 + res2);
    }
    else {
        return minNumberOfCoins(arr, size - 1, sum);
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << minNumberOfCoins(arr, size, 10) << endl;
    cout << minNumberOfCoins1(arr, size, 10) << endl;

    return 0;
}