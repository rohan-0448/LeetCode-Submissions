class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        stack<int> st;

        int n = a.size();
        vector<int> gt(10005, -1);
        for(int i=(2*n)-1; i>=0; i--) {
            if(i == (2*n)-1) {
                st.push(a[i%n]);
                gt[i%n] = -1;
            }
            else {
                while(!st.empty() && st.top() <= a[i%n]) st.pop();

                if(st.empty()) {
                    st.push(a[i%n]);
                    gt[i%n] = -1;
                }
                else {
                    gt[i%n] = st.top();
                    st.push(a[i%n]);
                }
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++) ans.push_back(gt[i]);

        return ans;
    }
};