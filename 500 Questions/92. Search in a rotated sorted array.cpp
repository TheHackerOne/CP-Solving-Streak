#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int binarySearch(vector<int> &nums, int target, int first, int last) {
        while (first <= last) {
            int mid = (first + last) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                last = mid - 1;
            } else first = mid + 1;
        }
        return INT_MAX;
    }

    int partitionIndex(vector<int> &a) {
        int first = 0, last = a.size() - 1;
        while (first < last) {
            int mid = (first + last) / 2;
            if (a[mid] > a[mid + 1]) {
                return mid;
            }
            else if (a[mid] > a[last]) {
                first = mid;
            } else if (a[mid] < a[last]) {
                last = mid;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            if (nums[0] == target) return 0;
            else return -1;
        }
        int partition = partitionIndex(nums);
        int index1 = binarySearch(nums, target, 0, partition);
        int index2 = binarySearch(nums, target, partition + 1, nums.size() - 1);

        if (index1 == INT_MAX && index2 == INT_MAX) return -1;
        else return index1 != INT_MAX ? index1 : index2;
    }
};

int main() {


    return 0;
}