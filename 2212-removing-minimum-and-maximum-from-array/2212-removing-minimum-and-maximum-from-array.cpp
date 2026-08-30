class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn_i = -1, mn = INT_MAX, mx_i = -1, mx = INT_MIN;

        for(int i=0; i<n; i++) {
            if(mn > nums[i]) {
                mn = nums[i];
                mn_i = i;
            }
            if(mx < nums[i]) {
                mx = nums[i];
                mx_i = i;
            }
        }

        int result = INT_MAX;
        // both left
        result = min(result, max(mx_i, mn_i)+1);

        // both right 
        result = min(result, n-min(mx_i, mn_i));

        // one left one right
        result = min(result, n-max(mx_i, mn_i) + min(mx_i, mn_i)+1);

        return result;
    }
};