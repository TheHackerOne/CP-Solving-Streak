class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        if(n == 0 ) return false;
        long long ans = n&(n-1);
        // cout<<ans<<endl;
        if(ans == 0) return true;
        else return false;
    }
};