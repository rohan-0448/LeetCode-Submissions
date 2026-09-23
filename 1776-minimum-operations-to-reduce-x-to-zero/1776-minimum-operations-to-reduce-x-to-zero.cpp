class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(begin(nums), end(nums), 0);
        int target = total - x;

        if(target == 0) return n;
        if(target < 0) return -1;

        int l = 0, sum = 0, res = -1;

        for(int r=0; r<n; r++) {
            sum += nums[r];
            while(l <= r && sum > target) sum -= nums[l++];

            if(sum == target) res = max(res, r - l + 1);
        }

        return res == -1 ? -1: n-res;
    }
};