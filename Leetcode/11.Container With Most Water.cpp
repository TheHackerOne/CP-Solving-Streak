class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i=0, j=n-1, maxWater = INT_MIN;
        while(i < j){
            int water = (j-i)*min(arr[i], arr[j]);
            maxWater = max(maxWater, water);
            if(arr[i] < arr[j]) i++;
            else j--;
        }
        return maxWater;
    }
};