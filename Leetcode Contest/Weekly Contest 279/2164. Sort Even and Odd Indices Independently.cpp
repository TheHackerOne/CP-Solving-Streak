class Solution {
public:
    
    static bool comp1(int a, int b){
        return a < b;
    }
    static bool comp2(int a, int b){
        return a > b;
    }
    
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> evenIdx, oddIdx;
        for(int i=0;i<nums.size();i++){
            if(i%2 == 0) evenIdx.push_back(nums[i]);
            else oddIdx.push_back(nums[i]);
        }
        
        sort(evenIdx.begin(), evenIdx.end(), comp1);
        sort(oddIdx.begin(), oddIdx.end(), comp2);
        int even = 0, odd = 0;
        for(int i=0;i<nums.size();i++){
            if(i%2 == 0) nums[i] = evenIdx[even++];
            else nums[i] = oddIdx[odd++];
        }
        
        return nums;
    }
};