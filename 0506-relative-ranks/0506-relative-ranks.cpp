class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int, string> mp;
        vector<int> score_cp = score;
        sort(score_cp.begin(), score_cp.end());
        reverse(score_cp.begin(), score_cp.end());
        
        int n = score_cp.size();
        if(n != 0) mp[score_cp[0]] = "Gold Medal";
        if(n > 1) mp[score_cp[1]] = "Silver Medal";
        if(n > 2) mp[score_cp[2]] = "Bronze Medal";
        for(int i=3; i<score_cp.size(); i++) mp[score_cp[i]] = to_string(i+1);
        
        // for(auto i: mp) cout << i.first << " " << i.second << endl;
        
        vector<string> v;
        for(auto i: score) v.push_back(mp[i]);

        return v;
    }
};