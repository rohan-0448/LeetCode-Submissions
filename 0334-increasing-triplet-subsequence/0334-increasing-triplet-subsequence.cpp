class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int first = INT_MAX, second = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= first) first = nums[i];
            else if(nums[i] <= second) second = nums[i];
            else return true;
        }
        return false;
    }
};