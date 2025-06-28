class Solution {
public:
    int sub(vector<int> &nums, int k) {
        int l = 0, r = 0, sum = 0, cnt = 0;

        while(r < nums.size()) {
            if(nums[r] % 2 == 1) sum++;

            while(sum > k) {
                if(nums[l] % 2 == 1) sum--;
                l++;
            }

            cnt += (r-l+1);
            r++;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return sub(nums, k) - sub(nums, k-1);
    }
};