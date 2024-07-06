class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int>dp(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]) dp[i] = max(dp[i], dp[j]+1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// class Solution {
// public:

//     void check(vector<int>& nums, int index, int& maxx, int size, int prev){
//         if(index == nums.size()) {
//             maxx = max(maxx, size);
//             return;
//         }

//         if(prev == -1001 || prev < nums[index]) check(nums, index+1, maxx, size+1, nums[index]);
//         check(nums, index+1, maxx, size, prev);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int maxx = INT_MIN;
//         check(nums, 0, maxx, 0, -1001);
//         return maxx;
//     }
// };