class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0, n = nums.size();
        for(int i=0; i<n; i++){
            if(i > mx) return false;
            if(mx >= n-1) return true;

            mx = max(mx, i+nums[i]);
        }
        return true;
    }
};