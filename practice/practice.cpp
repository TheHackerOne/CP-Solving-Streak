#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int initSum = 0, totalSum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        totalSum += arr[i];
        initSum += (i*arr[i]);
    }
    int maxSum = initSum;
    for(int i=n-1;i>=0;i--){
        initSum += totalSum - (arr[i]*(n));
        maxSum = max(maxSum, initSum);
    }

    cout<<maxSum<<endl;

    return 0;
}
