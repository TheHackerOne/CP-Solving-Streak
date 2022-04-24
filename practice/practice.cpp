#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;

class triple{
public:
    int idx;
    int capA;
    int capB;

    triple(int i, int capA, int capB){
        this->idx = i;
        this->capA = capA;
        this->capB = capB;
    }
};

long long solve(int idx, int n, int capA, int capB, vector<int> &hallA, vector<int> &hallB, map<triple*, int> &dp) {
    // base case
    if(idx == n){
        return 0;
    }

    // memoize
    triple *t = new triple(idx, capA, capB);
    if(dp.find(t) != dp.end()) return dp[t];

    // main logic
    long long op1 = INT_MAX;
    if(capA < n/2){
        op1 = (hallA[idx] + solve(idx+1, n, capA+1, capB, hallA, hallB, dp))%MOD;
    }
    long long op2 = INT_MAX;
    if(capB < n/2){
        op2 = (hallB[idx] + solve(idx+1, n, capA, capB+1, hallA, hallB, dp))%MOD;
    }

    return  dp[t] = min(op1, op2);
}

int organizeTheClass(int N, vector<int> hallA, vector<int> hallB){
    map<triple*, int> dp; 
    return solve(0, N, 0, 0, hallA, hallB, dp)%MOD;
}


int main() {
#ifndef ONLINE_JUDGE  
    freopen("Error.txt", "w", stderr);
#endif

    int t;
    cin >> t;
    while (t--) {
        cout<<organizeTheClass(4, {10, 30, 350, 30}, {20, 200, 50, 30});
    }

    return 0;
}