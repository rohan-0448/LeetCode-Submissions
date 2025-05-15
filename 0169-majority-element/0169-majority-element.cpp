class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0, mx = nums[0];
        for(auto i: nums){
            if(i == mx) c++;
            else{
                c--;
                if(c<0){
                    mx = i;
                    c = 1;
                }
            }
        }
        return mx;
    }
};