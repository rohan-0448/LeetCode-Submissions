class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        for(auto i: s) {
            mp[i]++;
        }

        int mn_e = INT_MAX, mn_o = INT_MAX, mx_e = INT_MIN, mx_o = INT_MIN;
        for(auto i: mp) {
            int freq = i.second;
            if(freq % 2 == 1) {
                // mn_o = min(mn_o, freq);
                mx_o = max(mx_o, freq);
            }
            else {
                mn_e = min(mn_e, freq);
                // mx_e = max(mx_e, freq);
            }
        }

        return mx_o - mn_e;
        // return max(abs(mx_o - mn_e), abs());
    }
};