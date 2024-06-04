class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int odd = 0;
        for(auto i: s) {
            mp[i]++;
            if(mp[i]%2==1) odd++;
            else odd--;
        }
        if(odd>1) return s.length()-odd+1;
        return s.length();
    }
};