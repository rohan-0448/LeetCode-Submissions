class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, num = nums[0];
        for(auto i: nums){
            if(i == num) cnt++;
            else cnt--;
            
            if(cnt < 0){
                num = i;
                cnt = 0;
            }
        }
        return num;
    }
};