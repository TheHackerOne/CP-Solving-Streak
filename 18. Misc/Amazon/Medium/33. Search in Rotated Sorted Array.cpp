class Solution {
public:
   int search(vector<int>& nums, int target) {
    if(nums.size() == 1 ){
      if(nums[0] == target) return 0;
      else return -1;
   }
   int pivot = -1;
   int n = nums.size();
   int first = 0, last = n-1;
   while(first <= last){
      int mid = (first+last)/2;
      if(nums[mid] > nums[mid+1]){
         pivot = mid;
         break;
      }else if(nums[mid] > nums[n-1]){
         first = mid+1;
      }else if(nums[mid] < nums[0]){
         last = mid-1;
      }else break; //IMPORTANT STEP
   }
   if(pivot == -1) pivot = n-1;
   int ans = -1;
   if(target >= nums[0] and target <= nums[pivot]){
      first = 0, last = pivot;
      while(first <= last){
         int mid = (first+last)/2;
         if(nums[mid] == target){
            return mid;
         }else if(nums[mid] > target){
            last = mid-1;
         }else {
            first = mid+1;
         }
      }
   }else{
      first = pivot+1, last = n-1;
      while(first <= last){
         int mid = (first+last)/2;
         if(nums[mid] == target){
            return mid;
         }else if(nums[mid] > target){
            last = mid-1;
         }else {
            first = mid+1;
         }
      }
   }
   return ans;
}
};