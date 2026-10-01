class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto &i: s) {
            if(!st.empty() && ((i == ')' && st.top() == '(') || (i == ']' && st.top() == '[') || (i == '}' && st.top() == '{'))) st.pop();
            else st.push(i);
        }

        return st.empty();
    } 
};