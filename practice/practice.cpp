class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
         int fix = nums[i];
         int remSum = -fix;
         int first = i+1, last = n-1;
         while(first < last){
            int sum = nums[first]+nums[last];
            if(sum == remSum){
               ans.push_back({ nums[i], nums[first], nums[last] });
               first++, last--;
            }else if(sum < remSum){
               first++;
            }else{
               last++;
            }
         }
        }

        return ans;
    }
};
[-2,-1, 1, 2]