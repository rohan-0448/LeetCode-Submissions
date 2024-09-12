class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mp;
        for(auto i: allowed) mp[i]++;
        int ans = 0;
        for(auto i: words){
            for(auto j: i){
                if(mp[j] == 0) {
                    ans--;
                    break;
                }
            }
            ans++;
        }
        return ans;
    }
};