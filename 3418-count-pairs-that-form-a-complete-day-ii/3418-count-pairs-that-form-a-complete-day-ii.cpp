class Solution {
public:
    long long countCompleteDayPairs(vector<int>& h) {
        int n = h.size();
        long long ans = 0;
        unordered_map<int , int>mp;
        for(int i = 0; i < n; i++){
            int m = h[i] % 24;
            if(mp.count(m)) ans += mp[m];
            mp[(24 - m)%24]++;
        }
        
        return ans;
    }
};