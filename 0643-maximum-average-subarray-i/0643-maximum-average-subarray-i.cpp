class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0, right = 0;
        double sum = 0.0;
        while(right<nums.size() && right<k) sum += nums[right++];
        double average = sum/k;
        while(right<nums.size()){
            sum -= nums[left++];
            sum += nums[right++];
            average = max(average, sum/k);
        }
        return average;
    }
};