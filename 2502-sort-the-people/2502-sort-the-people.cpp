class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> vec;
        for(int i=0; i<names.size(); i++) vec.push_back({heights[i], names[i]});
        sort(vec.rbegin(), vec.rend());
        vector<string> ans;
        for(auto i: vec) ans.push_back(i.second);

        return ans;
    }
};