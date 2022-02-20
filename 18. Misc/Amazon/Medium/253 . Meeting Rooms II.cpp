class Solution {
public:

    int minMeetingRooms(vector<Interval> &intervals) {
         int n = intervals.size();
         vector<int> start, end;
         for(auto interval:intervals){
            start.push_back(interval.start);
            end.push_back(interval.end);
         }
         sort(start.begin(), start.end());
         sort(end.begin(), end.end());

         int rooms = 1, maxRooms = 1;
        //  for(auto i:start) cout<<i<<" ";
        //     cout<<endl;
        //  for(auto i:end) cout<<i<<" ";
        //     cout<<endl;

         int i = 1, j = 0;
         while(i < n and j < n){
            if(end[j] <= start[i]){
               rooms--;
               j++;
            }else{
               rooms++;
               i++;
            }
            maxRooms = max(maxRooms, rooms);
         }
         return maxRooms;
    }
};