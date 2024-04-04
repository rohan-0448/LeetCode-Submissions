class Solution {
public:
    int maxDepth(string s) {
        int p = 0, max_p = 0;
        unordered_map<char, int> mp;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') p++;
            else if(s[i] == ')') p--;
            
            else if(s[i] != '+' || s[i] != '*' || s[i] != '-' || s[i] != '/') mp[s[i]] = p;
            
            max_p = max(max_p, p);
        }
        return max_p;
        for(auto i: mp) if(i.second == max_p) return i.first-'0';
        return -1;
    }
};