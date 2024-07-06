class Solution {
public:
    string simplifyPath(string path) {
        int index = 0, n = path.length(), prev = 0;
        stack<string> st;
        while(index <= n){
            if(path[index] == '/' || index == n) {
                string temp = path.substr(prev, index-prev);
                if(temp != "/" && temp != "/." && temp != "/..") st.push(temp);
                if(temp == "/..") if(st.empty()==false) st.pop();
                prev = index;
            }
            index++;
        }
        string ans = "";
        while(st.empty()==false){
            ans = st.top() + ans;
            st.pop();
        }
        if(ans=="") return "/";
        else return ans;
    }
};