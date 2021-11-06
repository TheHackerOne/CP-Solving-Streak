class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int largestPowerOf2inrange(int n){
        int x = 0;
        while((1 << x) <= n){
            x++;
        }
        return x-1;
    }
    
    int countSetBits(int n)
    {
        if(n == 0) return 0;
        int ans = 0;
        int ct2 = largestPowerOf2inrange(n);
        int firstPart = pow(2, ct2-1)*ct2;
        int secondPart = n - pow(2, ct2) + 1;
        ans = firstPart + secondPart + countSetBits(secondPart-1);
        
        return ans;
    }
};