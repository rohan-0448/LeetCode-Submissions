class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1, mp2;

        for(int i=0; i<s.length(); i++){
            char chs = s[i], cht = t[i];
            if(mp1.find(chs) != mp1.end()) {
                if(mp1[chs] != cht) return false;
            }
            else if(mp2.find(cht) != mp2.end()) return false;
            else{
                mp1[chs] = cht;
                mp2[cht] = chs;
            }
        }
        return true;
    }
};
        // for(int i=0; i<s.length(); i++){
        //     char chs = s[i], cht = t[i];
        //     if(mp1.find(chs) != mp1.end()) {
        //         if(mp1[chs] != cht) return false;
        //     } else if(mp2.find(cht) != mp2.end()) {
        //         return false;
        //     } else {
        //         mp1[chs] = cht;
        //         mp2[cht] = chs;
        //     }
        // }