class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_set<char> st;
        for(int i=0; i<s.length(); i++){
            if(mp.find(s[i]) == mp.end()) {
                if(st.find(t[i]) != st.end()) return false;
                st.insert(t[i]);
                mp[s[i]] = t[i];
            }
            else {
                if(mp[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};