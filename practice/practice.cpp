#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int target){
    int lo = 0, hi = arr.size()-1;
    int res = -1;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(arr[mid] == target){
            if(mid-1 >= 0 and arr[mid-1] == target) {
                hi = mid-1;
            }else{
                return mid;
            }
        }else if(arr[mid] > target){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }

    return res;
}

int upperBound(vector<int> &arr, int target){
    int lo = 0, hi = arr.size()-1;
    int n = arr.size();
    int res = -1;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(arr[mid] == target){
            if(mid+1 < n and arr[mid+1] == target) {
                lo = mid+1;
            }else{
                return mid;
            }
        }else if(arr[mid] > target){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }

    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;

    int lo = lowerBound(arr, target);
    int hi = upperBound(arr, target);
    cout<<lo<<" "<<hi<<endl;

    return 0;
}