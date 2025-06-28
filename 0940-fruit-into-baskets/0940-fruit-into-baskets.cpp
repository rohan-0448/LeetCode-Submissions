class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int r = 0, l = 0, max_len = INT_MIN, n = fruits.size();

        while(r < n) {
            mp[fruits[r]]++;

            if(mp.size() > 2) {
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }

            if(mp.size() <= 2) max_len = max(max_len, r-l+1);
            r++;
        }
        
        return max_len;
    }
};