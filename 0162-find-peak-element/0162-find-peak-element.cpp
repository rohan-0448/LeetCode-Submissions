class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;
        for(int i=0; i<n; i++) {
            if(i==0 && nums[i]>nums[i+1]) return i;
            else if(i==n-1 && nums[i]>nums[i-1]) return i;
            else if (nums[i]>nums[i+1] && nums[i]>nums[i-1]) return i;
        }
        return 0;
    }
};