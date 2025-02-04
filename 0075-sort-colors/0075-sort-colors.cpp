class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int st = 0, ed = n-1;

        for(int i=0; i<=ed; i++){
            if(nums[i]==0){
                nums[i] = nums[st];
                nums[st++] = 0;
            }
            else if(nums[i]==2){
                nums[i] = nums[ed];
                nums[ed--] = 2;
                i--;
            }
        }
    }
};