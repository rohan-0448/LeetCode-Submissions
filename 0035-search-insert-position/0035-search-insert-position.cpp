class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, ans = 0;

        while(low <= high) {
            int mid = low + (high-low) / 2;

            if(nums[mid] <= target) {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }

        if(nums[ans] >= target) return ans;
        else return ans+1;
    }
};