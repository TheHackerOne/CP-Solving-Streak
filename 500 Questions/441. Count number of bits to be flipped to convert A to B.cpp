class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        int count = 0;
        while((a != 0) || (b!= 0)){
            if(((a&1) && ((b&1) == 0)) || (((a&1) == 0) && (b&1))){
                count++;
            }
            a >>= 1;
            b >>= 1;
        }
        return count;
    }
};