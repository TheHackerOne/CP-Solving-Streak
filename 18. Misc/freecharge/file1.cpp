// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);
    // 1 2 3 4 3
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // create a map [int, bool]
    unordered_map<int , bool> mp;

    for(int i=0;i<n;i++){
        mp[arr[i]] = true;
    }
    // 1 - true
    // 2 - true
    // 3 - true
    // 4 - true

    vector<int> ans(n);
    // create the ans array

    // 1 - true
    // 2 - true
    // 3 - true
    // 4 - true

    for(int i=0;i<n;i++){
        // 1 2 3 4 3
        int ele = arr[i] + 1;
        //ele = 4 + 1 = 5

        if(mp.find(ele) != mp.end()){
            ans[i] = ele;
        }else{
            ans[i] = -1;
        }
    }

    // output the ans array

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}

