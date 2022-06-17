#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> arr1(n);
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }

    int m;
    cin>>m;
    vector<int> arr2(m);
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }

    vector<int>ans;

    int i = 0, j = 0;
    while(i != n and j != m){
        if(arr1[i] == arr2[j]){
            if(ans.empty()){
                ans.push_back(arr1[i]);
            }else{
                if(ans.back() != arr1[i]){
                    ans.push_back(arr1[i]);
                }
            }
            i++, j++;
        }else{
            int smaller = arr1[i] < arr2[j] ? arr1[i] : arr2[j]; 
            if(ans.empty()){
                ans.push_back(smaller);
                if(arr1[i] == smaller) i++;
                else j++;
            }else{
                if(ans.back() == smaller){
                }else{
                    ans.push_back(smaller);
                }
                if(arr1[i] == smaller) i++;
                else j++;
            }
        }
    }

    while(i != n){
        if(arr1[i] != ans.back()) ans.push_back(arr1[i]);
        i++;
    }
    while(j != m){
        if(arr2[j] != ans.back()) ans.push_back(arr2[j]);
        j++;
    }


    for(auto i:ans) cout<<i<<" ";
}

int main() {
#ifndef ONLINE_JUDGE  
    freopen("Error.txt", "w", stderr);
#endif

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}