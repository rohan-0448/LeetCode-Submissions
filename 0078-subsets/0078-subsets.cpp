class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int> &nums, int index, vector<int> curr) {
        if(index == nums.size()) {
            res.push_back(curr);
            return;
        }

        // not take
        solve(nums, index+1, curr);
        // take
        curr.push_back(nums[index]);
        solve(nums, index+1, curr);

        curr.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, 0, {});
        return res;
    }
};