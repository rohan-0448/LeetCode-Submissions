class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') st.push(i);
            if(s[i] == ')') {
                int n = st.top();
                st.pop();

                reverse(begin(s)+n, begin(s)+i);
            }
        }

        string ans = "";

        for(auto &i: s) if(i != '(' && i!= ')') ans += i;

        return ans;
    }
};