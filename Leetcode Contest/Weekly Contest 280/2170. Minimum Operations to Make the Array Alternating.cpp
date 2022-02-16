class Solution {
public:
   static bool comp(pair<int, int> &a,pair<int, int> &b){
        return a.first > b.first;
    }
int minimumOperations(vector<int>& nums) {
    if(nums.size() <= 1) return 0;
    vector<pair<int, int>> arr1, arr2;
    unordered_map<int, int> mp1,mp2;
    for(int i=0;i<nums.size();i++){
        if(i%2 == 0){
            mp1[nums[i]]++;
        }else{
            mp2[nums[i]]++;
        }
    }

    for(auto i:mp1){
        arr1.push_back({ i.second, i.first }); // count, element
    }

    for(auto i:mp2){
        arr2.push_back({ i.second, i.first }); // count, element
    }

    sort(arr1.begin(), arr1.end(), comp);
    sort(arr2.begin(), arr2.end(), comp);

    int maxCount1 = arr1[0].first, maxCount2 = arr2[0].first;
    int max1 =arr1[0].second, max2 = arr2[0].second;

    if(max1 == max2){
        // make max1 lose
        int cnt1 = 0;
        if(arr1.size() == 1){
            max1 = max2+1;
            maxCount1 = 0;
        }else{
            max1 = arr1[1].second;
            maxCount1 =arr1[1].first;
        }

        if(maxCount1 > maxCount2){
            int cnt = 0;
            for(int i=0;i<nums.size();i+=2){
                if(nums[i] != max1) cnt++;
                if(i+1 < nums.size() and nums[i+1] != max2) cnt++;
            }
            cnt1 = cnt;
        }else{
            int cnt = 0;
            for(int i=1;i<nums.size();i+=2){
                if(nums[i] != max2) cnt++;
                if(nums[i-1] != max1) cnt++;
            }
            if(nums.size()%2){
                if(nums[nums.size()-1] != max1) cnt++;
            }
            cnt1 = cnt;
        }

        // make max2 lose
        maxCount1 = arr1[0].first, maxCount2 = arr2[0].first;
        max1 =arr1[0].second, max2 = arr2[0].second;

        int cnt2 = 0;
        if(arr2.size() == 1){
            max2 = max1+1;
            maxCount2 = 0;
        }else{
            max2 = arr2[1].second;
            maxCount2 =arr2[1].first;
        }

        if(maxCount1 > maxCount2){
            int cnt = 0;
            for(int i=0;i<nums.size();i+=2){
                if(nums[i] != max1) cnt++;
                if(i+1 < nums.size() and nums[i+1] != max2) cnt++;
            }
            cnt2= cnt;
        }else{
            int cnt = 0;
            for(int i=1;i<nums.size();i+=2){
                if(nums[i] != max2) cnt++;
                if(nums[i-1] != max1) cnt++;
            }
            if(nums.size()%2){
                if(nums[nums.size()-1] != max1) cnt++;
            }
            cnt2= cnt;
        }

        return min(cnt1, cnt2);
    }
    if(maxCount1 > maxCount2){
        int cnt = 0;
        for(int i=0;i<nums.size();i+=2){
            if(nums[i] != max1) cnt++;
            if(i+1 < nums.size() and nums[i+1] != max2) cnt++;
        }
        return cnt;
    }else{
        int cnt = 0;
        for(int i=1;i<nums.size();i+=2){
            if(nums[i] != max2) cnt++;
            if(nums[i-1] != max1) cnt++;
        }
        if(nums.size()%2){
            if(nums[nums.size()-1] != max1) cnt++;
        }
        return cnt;
    }
}
};