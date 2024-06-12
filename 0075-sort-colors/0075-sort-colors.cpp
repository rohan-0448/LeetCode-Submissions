class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ind1 = 0, n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 0) {
                swap(nums[ind1], nums[i]);
                ind1++;
            }
        }
        for(int i=ind1; i<n; i++){
            if(nums[i] == 1) {
                swap(nums[ind1], nums[i]);
                ind1++;
            }
        }
    }
};