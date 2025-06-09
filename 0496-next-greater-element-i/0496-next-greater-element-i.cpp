class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        
        int n = nums2.size();
        vector<int> gt(10000+5, 0);
        for(int i=n-1; i>=0; i--) {
            if(i == n-1) {
                st.push(nums2[i]); // 
                gt[nums2[i]] = -1; // 0 3 -1 4 -1
            }
            else {
                while(!st.empty() && st.top() < nums2[i]) st.pop();
                if(st.empty()) {
                    st.push(nums2[i]); // 4
                    gt[nums2[i]] = -1;
                }
                else {
                    gt[nums2[i]] = st.top(); //  
                    st.push(nums2[i]); // 4 3 1
                }
            }
        }
        
        vector<int> ans;
        for(auto i: nums1) {
            ans.push_back(gt[i]);
        }

        return ans;
    }
};