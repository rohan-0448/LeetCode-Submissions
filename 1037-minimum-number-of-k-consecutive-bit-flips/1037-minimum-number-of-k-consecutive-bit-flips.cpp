class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int i = 0, n = nums.size(), c = 0, isflipped = 0;
        
        while(i<n){
            if(i>=k && nums[i-k]==7) isflipped--;
            if(nums[i]==(isflipped%2)){
                if(i+k > n) return -1;
                isflipped++;
                c++;
                nums[i]= 7;
            }
            i++;
        }

        return c;
    }
};