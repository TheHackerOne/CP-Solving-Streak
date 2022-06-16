#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<int> maxArr(n);
        int maxTillNow = INT_MIN;
        int maxIdx = -1;
        for(int i=n-1;i>=0;i--){
            if(arr[i] > maxTillNow){
                maxTillNow = arr[i];
                maxArr[i] = maxTillNow;
                maxIdx = i;
            }else{
                maxArr[i] = maxIdx;
            }
        }

        for(int i=0;i<n-1;i++){
            int maxIdx = maxArr[i+1];   
            if(arr[maxIdx] > arr[i]){
                swap(arr[maxIdx], arr[i]);
                break;
            }
        }

        for(auto i:arr) cout<<i<<" ";
            cout<<endl;
    }

    return 0;
}