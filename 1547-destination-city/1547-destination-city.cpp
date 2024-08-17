class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, bool> start;
        for(auto i: paths) start[i[0]] = true;;
        for(auto i: paths) if(start[i[1]] == false) return i[1];
        return "";
    }
};