class Solution {
public:
    int firstUniqChar(string s) {
        int map[26]={0};
        for(int i=0;i<s.length();i++){
            map[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(map[s[i]-'a'] == 1) return i;
        }
        return -1;
        // unordered_map<char, int> mp(26);
        // for(auto i: s) mp[i]++;
        // // for(auto i: mp) cout << i.first << " " << i.second << endl;
        // char ans = '0';
        // for(auto i: mp) if(i.second == 1) ans = i.first;
        // cout << ans << endl;
        // for(int i=0; i<s.length(); i++) if(s[i] == ans) return i;
        // return -1;
    }
};