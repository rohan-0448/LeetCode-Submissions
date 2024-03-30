class Solution {
public:
    string removeStars(string s) {
        // string ans = "";
        int len = 0;
        for(auto i: s){
            if(i!='*') s[len++]=i;
            else len--;
        }
        // string ans = "";
        // while(!st.empty()){
            // ans = st.top()+ans;
            // st.pop();
        // }
        return s.substr(0,len);
    }
};