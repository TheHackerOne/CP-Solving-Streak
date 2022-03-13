class Solution {
public:
   double getDistance(int x, int y){
      return sqrt(pow(x,2)+pow(y,2));
   }

   vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
     priority_queue<pair<double, pair<int, int>>> pq;

     for(auto point:points){
         int x = point[0], y = point[1];
         double distanceFromOrigin = getDistance(x, y);
         pq.push({ distanceFromOrigin, { x, y } });
         if(pq.size() > k){
            pq.pop();
         }
     }

     vector<vector<int>> res;
     while(!pq.empty()){
      pair<double, pair<int, int>> point = pq.top();
      res.push_back({ point.second.first, point.second.second });
      pq.pop();
     }
     return res;
   }
};