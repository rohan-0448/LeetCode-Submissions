class Solution {
public:

    unordered_map<char, int> mp;

    static bool comp(unordered_map<char, int> mp, char a, char b){
        if(mp[a] != 0 && mp[b != 0]) return mp[a] < mp[b];
        else if(mp[a] == 0 && mp[b] != 0) return mp[a] < mp[b];
        else if(mp[a] != 0 && mp[b] == 0) return mp[a] < mp[b];
        else return false;
    }

    string customSortString(string order, string s) {
        int val = 1;
        for(auto i: order) {
            mp[i] = val++;
        }
        
        // Use a lambda for comparison that captures mp by reference
        sort(s.begin(), s.end(), [this](char a, char b) {
            if(mp[a] != 0 && mp[b] != 0) return mp[a] < mp[b];
            else if(mp[a] == 0 && mp[b] != 0) return false;
            else if(mp[a] != 0 && mp[b] == 0) return true;
            else return a < b;
        });
        
        return s;
        // int val = 1;
        // for(auto i: order) {
        //     mp[i] = val;
        //     val++;
        // }
        // sort(s.begin(), s.end(), comp);
        // return s;
    }
};