class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) nums.push_back(nums[i]);

        // 1 2 3 4 5 6 1 2 3 4 5

        long long sum1 = 0, sum2 = 0;

        for(int i=0; i<n/2; i++) {
            sum1 += nums[i];
            sum2 += nums[i+(n/2)];
        }

        // [1,2,3] , [4,5,6]

        int cnt = 0;
        for(int i=0; i<n; i++) {
            // check first
            if(sum1 > sum2) cnt++;

            sum1 -= nums[i];
            sum1 += nums[i+n/2];

            sum2 -= nums[i+n/2];
            sum2 += nums[i+n];
        }

        return cnt;
    }
};