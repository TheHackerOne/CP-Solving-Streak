class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> ans;
      int n = nums.size();

      for(int i=0;i<n;i++){
         if(i == 0) ans[i] = nums[i];
         else ans[i] = ans[i-1]*nums[i];
      }

      int right = 1;

      for(int i=n-1;i>=0;i--){
         ans[i] = ans[i-1]*right;
         right *= nums[i];
      }

      return ans;
    }
};