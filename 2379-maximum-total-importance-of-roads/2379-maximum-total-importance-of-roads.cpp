class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int, long long> mp;
        for(auto i: roads) {
            mp[i[0]]++;
            mp[i[1]]++;
        }
        
        vector<long long> vec;
        for(auto i: mp) cout << i.first << " " << i.second << endl;
        for(auto i: mp) vec.push_back(i.second); 
        sort(vec.begin(), vec.end());
        
        long long ans = 0;
        int m = vec.size();
        for(int i=m-1; i>-1; i--) {
            ans += vec[i]*(n);
            n--;    
        }
        return ans;
    }
};