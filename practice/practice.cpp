#include<bits/stdc++.h>
using namespace std;

 int recur(int idx, int size, int energy, int teleports, vector<int> &A, unordered_map<string, int> &mp){
        if(idx == size){
            return idx;
        }
        string str = to_string(idx)+to_string(energy)+to_string(teleports);
        if(mp.find(str) != mp.end())return mp[str];
        int left = idx, right = idx;
        if(energy-abs(A[idx]-A[idx+1])>=0)
            left = max(left, recur(idx+1, size, energy-abs(A[idx]-A[idx+1]), teleports,A,mp));
        if(teleports > 0)
            right = recur(idx+1, size, energy, teleports-1, A, mp);
        return mp[str] = max({left, right, idx});
    }
    
    int solve (int N,vector<int> &A,int X,int K)
    {
        unordered_map<string,int> mp;
        int energy = X;
        int teleports = K;
        return recur(1, N, energy, teleports, A, mp)+1;
    }

int main(){
    int n, x,k;
    cin>>n>>x>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<solve(n,arr, x,k);
   

    return 0;
}