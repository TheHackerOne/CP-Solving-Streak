class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      vector<int> ans(n, 0);

      for(int i=0;i<n;i++){
         if(i == 0) ans[i] = nums[i];
         else ans[i] = ans[i-1]*nums[i];
      }

      int right = 1;

      for(int i=n-1;i>=0;i--){
         ans[i] = (i-1>=0?ans[i-1]:1)*right;
         right *= nums[i];
      }

      return ans;
    }
};