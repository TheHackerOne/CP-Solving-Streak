class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long res = 0;
            
        long long st = 0, en = 0;
        long long pos = 0, neg = 0;
        long long lastEn = 0;
        while(st < nums.size()){
            en = st;
            while(en+1 < nums.size() and nums[en] > nums[en+1]){
                en++;
            }
            if(st == en) st++;
            else {
                pos += nums[st];
                if(en + 1 != nums.size())
                    neg += nums[en];  
                lastEn = en;
                st = en + 1;
            }
        }
        lastEn++;
        long long maxEle = INT_MIN;
        for(int i=lastEn;i<nums.size();i++){
            if(nums[i] > maxEle ) maxEle = nums[i];
        }
        
        pos += (maxEle == INT_MIN ? 0 : maxEle);        
        
        res = pos - neg;
        
        if(res == 0){
            return *max_element(nums.begin(), nums.end());
        }
        
        return res;
    }
};