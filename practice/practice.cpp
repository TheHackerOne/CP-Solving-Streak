#include<bits/stdc++.h>
class Solution {
private:
    long long max(long long a, long long b){
        return a > b ? a : b;
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        
        // suffix value array
        long long n = events.size();
        vector<long long> sufMax(n, 0);
        
        for(long long i=n-1;i>=0;i--){
            if(i == n-1) sufMax[i] = events[i][2];
            else sufMax[i] = max(events[i][2], sufMax[i+1]);
        }
        
        long long res = INT_MIN;
        
        for(long long i=0;i<n;i++){
            res = max(res, events[i][2]);
        }
        
        for(long long i=0;i<n;i++){
            long long sum = events[i][2];
            long long lo = i+1, hi = n-1;
            long long res = -1;
            while(lo <= hi){
                long long mid = (lo + hi)/2;
                if(events[mid][0] > events[i][1]){
                    res = mid;
                    hi = mid-1;
                }else{
                    lo = mid+1;
                }
            }
            if(res != -1){
                long long maxVal = sufMax[res];
                sum += maxVal;
                res = max(res, maxVal);
            }
        }
        
        return maxVal;
    }
};