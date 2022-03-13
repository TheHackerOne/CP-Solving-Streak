class RandomizedSet {
private:
    unordered_map<int, int> mp; // value, index
    vector<int> arr;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            arr.push_back(val);
            mp[val] = arr.size()-1;
            return true;
        }else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()){
            return false;
        }else{
            int idx = mp[val];
            int size = arr.size();
            swap(arr[idx], arr[size-1]);
            mp[arr[idx]] = idx;
            mp.erase(val);
            arr.pop_back();
            return true;
        }
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */