class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(begin(nums1), end(nums1));

        if(mn % 2 == 1) return true;
        else for(auto &i: nums1) if(i % 2 == 1) return false;
        return true;
    }
};