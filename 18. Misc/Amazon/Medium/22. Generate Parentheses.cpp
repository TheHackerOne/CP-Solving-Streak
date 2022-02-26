class Solution {
public:
    void recur(int open, int close, int n, string asf, vector<string> &res){
        // base case
        if(open > n or close > n) return;
        if(open == n and close == n){
            res.push_back(asf);
            return;
        }
        
        // main logic
        if(open == close) recur(open+1, close, n, asf+"(", res);
        if(open > close){
            recur(open+1, close, n, asf+"(", res);
            recur(open, close+1, n, asf+")", res);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        vector<string> res;
        recur(open, close, n, "", res);
        return res;
    }
};