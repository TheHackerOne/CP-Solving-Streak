class Solution {
private:
    vector<string> mapping = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };    
public:
    vector<string> helper(string digits){
        // base case
        if(digits.length() == 0){
            vector<string> res;
            res.push_back("");
            return res;
        }
        
        // main logic
        string nums = mapping[digits[0]-'0'];
        vector<string> ans;
        vector<string> res = helper(digits.substr(1));
        for(int i=0;i<nums.length();i++){
            char ch = nums[i];
            for(int j=0;j<res.size();j++){
                ans.push_back(ch+res[j]);
            }
        }
        return ans;
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        ans = helper(digits);
        return ans;
    }
};