void sort012(int *arr, int n){
   int zeroCount = 0, oneCount = 0, twoCount = 0;
   for(int i=0;i<n;i++){
      if(arr[i] == 0) zeroCount++;
      else if(arr[i] == 1) oneCount++;
      else twoCount++;
   }

   int idx =0;
   while(zeroCount--){
      arr[idx++] = 0;
   }
   while(oneCount--){
      arr[idx++] = 1;
   }
   while(twoCount--){
      arr[idx++] = 2;
   }
   return arr;
}

void sort012(int *arr, int n){
   int left = -1, right = n;

   for(int i=0;i<n;i++){
      if(i >= right) break;
      if(arr[i] == 0){
         left++;
         swap(arr[left], arr[i]);
      }else if(arr[i] == 2){
         right--;
         swap(arr[i], arr[right]);
         i--;
      }
   }

}