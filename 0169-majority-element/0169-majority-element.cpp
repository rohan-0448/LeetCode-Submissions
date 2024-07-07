class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0, num=nums[0];
        for(auto i: nums){
            if(i == num) c++;
            else c--;

            if(c <= 0) {
                num = i;
                c=1;
            }
        }
        return num;
    }
};