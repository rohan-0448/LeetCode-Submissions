class RandomizedSet {
public:
    unordered_map<int, int> mp;
    int size = 0;
    RandomizedSet() {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    }
    
    bool insert(int val) {
        // cout << "before insert" << endl;
        // for(auto i: mp) cout << i.first << "-" << i.second << ", ";
        // cout << endl;

        if(mp[val] == 0) {
            mp[val]++;
            size++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        // cout << "before remove" << endl;
        // for(auto i: mp) cout << i.first << "-" << i.second << ", ";
        // cout << endl;

        if(mp[val]){
            mp[val]--;
            size--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        // cout << "before random" << endl;
        // for(auto i: mp) cout << i.first << "-" << i.second << ", ";
        // cout << endl;

        int t = rand() % size+1;
        for(auto i: mp){
            if(i.second){
                t-=i.second;
                if(t<=0) return i.first;
            }
        }
        return -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */