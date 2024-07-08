class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return {};

        int s = 0, e = 0;
        vector<string> ans;

        while(e< nums.size()-1){
            if(nums[e+1] == nums[e] + 1) e++;
            else{
                if(s==e) ans.push_back(to_string(nums[s]));
                else ans.push_back(to_string(nums[s]) + "->" + to_string(nums[e]));

                e++;
                s = e;
            }
        } 

        if(s==e) ans.push_back(to_string(nums[s]));
        else ans.push_back(to_string(nums[s]) + "->" + to_string(nums[e]));

        return ans;
    }
};