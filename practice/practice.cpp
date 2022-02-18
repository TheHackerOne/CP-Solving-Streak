

int lowerBound(vector<int> &arr, int n, int k){
   int low = 0, high = n-1, ans = -1;
   while(low <= high){
      int mid = (low+high)/2;
      if(arr[mid] == k){
         ans = mid;
         high = mid-1;
      }else{
         low = mid+1;
      }
   }
   return ans;
}

int upperBound(vector<int> &arr, int n, int k){
   int low = 0, high = n-1, ans = -1;
   while(low <= high){
      int mid = (low+high)/2;
      if(arr[mid] == k){
         ans = mid;
         high = mid-1;
      }else{
         low = mid+1;
      }
   }
   return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k){
   pair<int, int> ans;
   ans.first = lowerBound(arr, n, k);
   ans.second = upperBound(arr, n, k);

   return ans;
}