class Solution {
   public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        vector<int> distinctCount(nums.size() + 1, 0);
        int totalCount = 0, left = 0, right = 0, currCount = 0;

        while (right < nums.size()) {
            if (++distinctCount[nums[right++]] == 1) k--;

            if (k < 0) {
                --distinctCount[nums[left++]];
                k++;
                currCount = 0;
            }

            if (k == 0) {
                while (distinctCount[nums[left]] > 1) {
                    --distinctCount[nums[left++]];
                    currCount++;
                }
                totalCount += (currCount + 1);
            }
        }
        return totalCount;
    }
};