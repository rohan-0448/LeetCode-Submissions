class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0;

        vector<int> changes(n+1, 0);
        for(auto i: queries){
            int left = i[0];
            int right = i[1];
            changes[left]++;
            changes[right+1]--;
        }

        for(int i=0; i<n; i++){
            sum += changes[i];
            if(sum<nums[i]) return false;
        }
        return true;
    }
};