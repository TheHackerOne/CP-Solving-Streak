#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(vector<long long> A, long long int N, long long int K) {

    queue<int> q;
    vector<long long> ans;

    int i = 0, j = 0;
    while (j < N) {
        if (A[j] < 0) q.push(A[j]);

        int windowSize = j - i + 1;

        if (windowSize < K) {
            j++;
        } else if ( windowSize == K) {
            if (q.empty()) ans.push_back(0);
            else {
                ans.push_back(q.front());
                if (A[i] == q.front())
                    q.pop();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    long long n, k;
    cin >> n ;

    vector<long long> arr(n + 1);

    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> k;

    vector<long long> ans = printFirstNegativeInteger(arr, n, k);

    for (auto i : ans) cout << i << " ";

    return 0;
}