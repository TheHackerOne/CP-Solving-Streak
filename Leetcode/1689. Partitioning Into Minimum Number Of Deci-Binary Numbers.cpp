class Solution {
public:
    int minPartitions(string n) {
        int maxEle = INT_MIN;
        for(int i=0;i<n.length();i++){
            maxEle = max(maxEle, n[i]-'0');
        }
        return maxEle;
    }
};