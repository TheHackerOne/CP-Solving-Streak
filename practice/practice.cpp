class Solution {
public:
  long long numberOfWeeks(vector<int>& milestones) {
      priority_queue<int> pq;
      for(auto i:milestones) pq.push(i);

      int ans = 0;

      while(pq.size() > 1){
        int first = pq.pop();
        int second = pq.pop();
        int diff = first - second;
        ans += min(first, second)*2;
        if(diff != 0) pq.push(diff);
      }
      return ans;
  }
};