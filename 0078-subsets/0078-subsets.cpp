class Solution {
public:
    
    void recur(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int index){
        if(find(ans.begin(), ans.end(), temp) == ans.end()) ans.push_back(temp);
        if(index == nums.size()) return;
        
        // take
        temp.push_back(nums[index]);
        recur(ans, temp, nums, index+1);
        // not take
        temp.pop_back();
        recur(ans, temp, nums, index+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        recur(ans, temp, nums, 0);
        return ans;
    }
};