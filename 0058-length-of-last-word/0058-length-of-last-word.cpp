class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] == ' ' && i == s.length()-1) while(s[i] == ' ') i--;
            if(s[i] == ' ') return len;
            else len++;
        }
        return len;
    }
};