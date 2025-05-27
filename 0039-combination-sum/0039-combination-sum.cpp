class Solution {
public:
    void recursive(int index, int length, vector<int> temp, vector<int> &candidates, 
        int sum, int target, vector<vector<int>> &st){
        if(sum == target) {
            st.push_back(temp);
            return;
        }
        if(index == length) {
            return;
        }

        // not pick
        recursive(index+1, length, temp, candidates, sum, target, st);
        // pick
        if(sum + candidates[index] <= target) {
            temp.push_back(candidates[index]);
            sum += candidates[index];
            recursive(index, length, temp, candidates, sum, target, st);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> st;
        // sort(candidates.begin(), candidates.end());

        recursive(0, candidates.size(), {}, candidates, 0, target, st);

        return st;

        // vector<vector<int>> ans;
        // for(auto i: st) ans.push_back(i);
        // return ans;
    }
};