class Solution {
public:
    /**
     * @param s: a string
     * @return: a root of this tree
     */
    int i = 0;
    TreeNode * str2tree(string &s) {
        int p = i;
        TreeNode *newNode = nullptr;
        while (i < s.length() && s[i] != '(' && s[i] != ')') i++;
        string str = s.substr(p, i);
        if (str.length() != 0) {
            int rootVal = stoi(str);
            newNode = new TreeNode(rootVal);
        }

        if (i < s.length() && s[i++] == '(') {
            newNode -> left = str2tree(s);
            if (i < s.length() && s[i++] == '(') {
                newNode -> right = str2tree(s);
                i++;
            }
        }
        return newNode;
    }
};