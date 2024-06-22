class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    
private:
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, right = 0, ans = 0;
        
        while (right < n) {
            if(nums[right] % 2 == 1) k--;
            while(k < 0) if(nums[left++] % 2 == 1) k++;
            ans += right - left + 1;
            right++;
        }

        return ans;
    }
};
