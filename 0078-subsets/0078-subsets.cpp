class Solution {
public:
    void recursive(int index, vector<int> temp, vector<int> &nums, vector<vector<int>>& ans){
        if(index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // not take - temp not updated, only index is updated
        recursive(index+1, temp, nums, ans);
        // take - temp updated - and index updated
        temp.push_back(nums[index]);
        recursive(index+1, temp, nums, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        recursive(0, {}, nums, ans);

        return ans;
    }
};