class RandomizedSet {
public:
    unordered_map<int, bool> mp;
    int size = 0;
    RandomizedSet() {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    }
    
    bool insert(int val) {
        if(mp[val] == false) {
            mp[val] = true;
            size++;
        }
        else return false;

        return true;
    }
    
    bool remove(int val) {
        if(mp[val] == true) {
            mp[val] = false;
            size--;
        }
        else return false;

        return true;
    }
    
    int getRandom() {
        int a = rand() % size;
        for(auto i: mp){
            if(i.second){
                if(a == 0) return i.first;
                else a--;
            }
        }
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */