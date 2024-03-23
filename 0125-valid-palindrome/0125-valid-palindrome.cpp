class Solution {
public:
    bool isPalindrome(string s) {
        string n = "";
        for(int i=0; i<s.length(); i++){
            if(isalnum(s[i])) n+=tolower(s[i]);
        }
        int len = n.length();
        for(int i=0; i<len+1/2; i++){
            // cout << n[i] << " " << n[n-i-1] << endl;
            if(n[i] != n[len-i-1]) return false;
        }
        return true;
    }
};