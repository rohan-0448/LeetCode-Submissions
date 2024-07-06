class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n,1e8);

        for(int i=0;i<n;i++){
            int id = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();

            dp[id] = nums[i];

        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]!=1e8) ans = i+1;
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