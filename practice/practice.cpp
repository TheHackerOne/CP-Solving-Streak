class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while(i < firstList.size() && j < secondList.size()){
            int s1 = firstList[i][0], e1 = firstList[i][1];
            int s2 = secondList[j][0], e2 = secondList[j][1];
            cout<<s1<<" "<<e1<<"   "<<s2<<" "<<e2<<endl;
            if(s2<=s1 && e2>=s1){
                ans.push_back({max(s1,s2), min(e1,e2)});
                if(e2 > e1) i++;
                else j++;
            }else if(s2<=e1 && e2>=e1){
                ans.push_back({max(s1,s2), min(e1,e2)});
                if(e2 > e1) i++;
                else j++;
            }else{
                if(e2 > e1) i++;
                else j++;
            }
        }
        return ans;
    }
};