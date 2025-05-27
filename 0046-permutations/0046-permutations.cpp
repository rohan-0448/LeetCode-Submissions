class Solution {
public:
    void recur(vector<int> curr, vector<int> left, vector<vector<int>> &ans) {
        if(left.size() == 0) {
            ans.push_back(curr);
            return;
        }

        for(int i=0; i<left.size(); i++) {
            int val = left[i];
            curr.push_back(val);
            left.erase(left.begin()+i);

            recur(curr, left, ans);
            
            curr.pop_back();
            left.insert(left.begin()+i, val);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        recur({}, nums, ans);

        return ans;
    }
};