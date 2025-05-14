class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> st;
        for(auto i: nums){
            int n = st.size();
            st.insert(i);
            if(st.size()==n) return i;
        }
        return -1;
    }
};