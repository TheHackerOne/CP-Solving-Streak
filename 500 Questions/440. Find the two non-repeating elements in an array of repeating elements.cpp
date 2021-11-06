class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        vector<int> ans;
        
        int unequalBit, xorAll = 0;
        for(int i=0;i<nums.size();i++){
            xorAll ^= nums[i];
        }
        
        int i = 0;
        
        while(xorAll != 0){
            if(xorAll&1){
                break;
            }
            i++;
            xorAll >>= 1;
        }
        
        unequalBit = i;
        int xor1 = 0, xor2 = 0;
        
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            num >>= unequalBit;
            if(num&1){
                xor1 ^= nums[i];
            }else{
                xor2 ^= nums[i];
            }
        }
        
        ans.push_back(xor1);
        ans.push_back(xor2);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};