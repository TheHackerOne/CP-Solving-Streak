class Solution {
public:
    int recur(int idx, int n, vector<int> &slots, vector<int> &nums, map<pair<int, vector<int>>, int> &dp){
        // Base Case
        if(idx == n){
            return 0;
        }
        
        // Memoization 
        if(dp.find({ idx, slots }) != dp.end()) return dp[{ idx, slots }];
        
        // Main Logic
        int ans=INT_MIN, num = nums[idx];
        
        for(int i=0;i<slots.size();i++){
            if(slots[i] < 2){
                slots[i]++;
                int res = (num&(i+1)) + recur(idx+1, n, slots, nums, dp);
                ans = max(ans, res);
                slots[i]--;
            }
        }
        
        return dp[{ idx, slots }] = ans;
    }
    
    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<int> slots(numSlots, 0);
        map<pair<int, vector<int>>, int> dp;
        int ans = recur(0, nums.size(), slots, nums, dp);
        return ans;
    }
};