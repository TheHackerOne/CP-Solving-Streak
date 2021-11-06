class Solution {
  public:
    int countSetBitsFunc(int n){
        int count = 0;
        while(n != 0){
            if(n&1) count++;
            n >>= 1;
        }
        return count;
    }
    
    int positionOfSetBit(int n){
        int pos = 0;
        while(n != 0){
            if(n&1) break;
            pos++;
            n >>= 1;
        }
        return pos+1;
    }
  
    int findPosition(int N) {
        int countSetBits = countSetBitsFunc(N);
        if(countSetBits > 1 || countSetBits == 0){
            return -1;
        }
        return positionOfSetBit(N);
    }
};