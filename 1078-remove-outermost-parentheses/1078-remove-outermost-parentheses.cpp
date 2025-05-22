class Solution {
public:
    string check(int i, int j, string s){
        return s.substr(i+1, j-i-1);
    }

    string removeOuterParentheses(string s) {
        string ans = "";
        int left = 0, cnt = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') cnt++;
            if(s[i] == ')') cnt--;

            if(cnt == 0) {
                ans+= check(left, i, s);
                left = i+1;
            }
        }
        return ans;
    }
};