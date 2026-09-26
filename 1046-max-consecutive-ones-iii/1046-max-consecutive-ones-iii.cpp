class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, zeros = 0, mx_len = -1;
        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] == 0) zeros++;

            while(zeros > k) {
                if(nums[left] == 0) zeros--;
                left++;
            }

            mx_len = max(mx_len, right - left + 1);
        }
        return mx_len;
    }
};