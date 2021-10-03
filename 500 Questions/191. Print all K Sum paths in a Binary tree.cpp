class Solution {
public:
    int count = 0;
    unordered_map<int, int> mp;
    void pathSumHelper(TreeNode *root, int targetSum, unordered_map<int, int> &mp, int &sum, vector<int> &path) {
        // base case
        if (root == nullptr) return;

        // main logic
        sum += root->val;
        path.push_back(root->val);
        int occurence = sum - targetSum;
        if (mp.find(occurence) != mp.end()) {
            count += mp[occurence];
            int subarrays = mp[occurence], sum1 = 0;
            vector<int> allpath;
            int pos = path.size() - 1;
            while (subarrays--) {
                int i = 0;
                while (sum1 != targetSum || i == 0) {
                    allpath.push_back(path[pos]);
                    sum1 += path[pos];
                    pos--;
                    i++;
                }
                for (int j = 0; j < allpath.size(); j++) cout << allpath[j] << " ";
                cout << endl;
            }
        }

        mp[sum]++;
        pathSumHelper(root -> left, targetSum, mp, sum, path);
        pathSumHelper(root -> right, targetSum, mp, sum, path);
        path.pop_back();
        mp[sum]--;
        sum -= root -> val;
    }

    int pathSum(TreeNode* root, int targetSum) {

        mp[0] = 1;
        int sum = 0;
        vector<int> path;
        pathSumHelper(root, targetSum, mp, sum, path);
        return count;
    }
};