class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i: nums) mp[i]++;

        vector<pair<int, int>> vec;
        for(auto i: mp) vec.push_back({i.second, 101-i.first});

        sort(vec.begin(), vec.end());

        vector<int> ans;
        for(auto i: vec){
            int temp = i.first;
            while(temp--) ans.push_back(101-i.second);
        }

        return ans;
    }
};