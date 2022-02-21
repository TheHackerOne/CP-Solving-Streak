class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		deque<pair<int, int>> dq;
		int n = intervals.size();
		for(int i=0;i<n;i++){
			int start = intervals[i][0], end = intervals[i][1];
			if(dq.size() == 0){
				dq.push_back({ start, end });
			}else{
				pair<int, int> top = dq.back();
                dq.pop_back();
				int tpStart = top.first, tpEnd = top.second;
				if(tpStart <= start and start <= tpEnd){
					pair<int, int> ans;
					ans.first = min(start, tpStart);
					ans.second = max(end, tpEnd);
					dq.push_back(ans);
				}else{
					dq.push_back(top);
					dq.push_back({ start, end });
				}
			}
		}	
		vector<vector<int>> ans;
		for(auto i:dq){
			ans.push_back({ i.first, i.second });
		}
		return ans;
	}
};