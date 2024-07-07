class Solution {
public:
    string reverseWords(string s) {
        deque<string> rev;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] != ' '){
                string t = "";
                while(i < s.length() && s[i] != ' ') t += s[i++];
                i--;
                rev.push_front(t);
            }
        }
        string ans="";
        for(auto i: rev) ans += i+" ";
        return ans.substr(0, ans.size()-1);
        // reverse(rev.begin(), rev.end());
        // for(int i=0; i < rev.size() ; i++) cout << rev[i] << " ";
    }
};