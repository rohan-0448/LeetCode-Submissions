class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4) return 0;
        sort(nums.begin(), nums.end());

        int ans = INT_MAX, i = 0, j = n-4;
        
        while(j<n){
            ans = min(ans, abs(nums[i++]-nums[j++]));
        }

        return ans;
    }
};