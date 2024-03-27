class Solution {
public:    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int prod = 1, count = 0, start = 0, end = 0;
        while(end < nums.size()){
            prod *= nums[end];
            while(start < nums.size() && prod >= k) prod /= nums[start++];
            if(prod < k) count += end - start + 1;
            end++;
        }
        return count;
    }
};