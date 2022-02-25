/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> list;
    int curr = 0;
    
    void helper(vector<NestedInteger> &nested){
        for(int i=0;i<nested.size();i++){
            if(nested[i].isInteger()) {
                list.push_back(nested[i].getInteger());
            }else{
                helper(nested[i].getList());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }
    
    int next() {
        return list[curr++];
    }
    
    bool hasNext() {
        if(curr >= list.size()) return false;
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */