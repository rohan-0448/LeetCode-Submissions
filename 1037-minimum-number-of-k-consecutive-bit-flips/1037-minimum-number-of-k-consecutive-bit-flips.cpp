class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int l = 0, n = nums.size(), ans = 0, isflipped = 0;
        
        while(l<n){
            if(l>=k && nums[l-k]==2) isflipped--;
            if(nums[l]==(isflipped%2)){
                if(l+k>n) return -1;
                isflipped++;
                ans++;
                nums[l]= 2;
            }
            l++;
        }
        
        return ans;
    }
};