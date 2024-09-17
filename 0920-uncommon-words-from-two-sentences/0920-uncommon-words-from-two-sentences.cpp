class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        int start = 0;
        for(int i=0; i<=s1.length(); i++) {
            if(i == s1.length() || s1[i]==' ') {
                mp[s1.substr(start, i-start)]++;
                start = i+1;
            }
        }
        start = 0;
        for(int i=0; i<=s2.length(); i++) {
            if(i == s2.length() || s2[i]==' ') {
                mp[s2.substr(start, i-start)]++;
                start = i+1;
            }
        }
        vector<string> ans;

        for(auto i: mp) if(i.second == 1) ans.push_back(i.first);

        return ans;
    }
};