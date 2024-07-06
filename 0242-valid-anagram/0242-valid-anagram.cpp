class Solution {
public:
    bool isAnagram(string s, string t) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        // map<char, int> mp1, mp2;

        // for(int i=0; i<s.size(); i++) mp1[s[i]]++;
        
        // for(int i=0; i<t.size(); i++) mp2[t[i]]++;

        // return mp1 == mp2;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};