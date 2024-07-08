class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        for(int a=0; a<nums.size(); a++){
            if(a>i) return false;
            i = max(i, a+nums[a]);
        }
        return true;
    }
};