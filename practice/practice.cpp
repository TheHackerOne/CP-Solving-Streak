class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long lo = 1, hi = accumulate(piles.begin(), piles.end(), 0); // speed
        int ans = -1;
        while(lo <= hi){
            long long mid = (lo+hi)/2;
            long long hrsNeeded = 0;
            for(long long i=0;i<piles.size();i++){
                long long div = ceil(piles[i]/(float)mid);
                hrsNeeded += div;
            }
            if(hrsNeeded > h){
                lo = mid+1;
            }else{
                ans = mid;
                hi = mid-1;
            }
        }
        return ans;
    }
};