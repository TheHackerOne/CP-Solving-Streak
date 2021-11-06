class Solution {
  public:
    int countSetBits(int n){
        int count = 0;
        while(n!=0){
            if(n&1) count++;
            n >>= 1;
        }
        return count;
    }
  
    int setBits(int N) {
        int count = countSetBits(N);
        return count;
    }
};