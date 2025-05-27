class Solution {
public:
    void recursive(int index, int length, vector<int> temp, vector<int> &candidates, 
        int sum, int target, vector<vector<int>> &st){
        
        if(sum == target) {
            st.push_back(temp);
            return;
        }

        for(int i=index; i<length; i++) {
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(sum + candidates[i] <= target) {
                temp.push_back(candidates[i]);
                recursive(i+1, length, temp, candidates, sum + candidates[i], target, st);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> st;
        sort(candidates.begin(), candidates.end());

        recursive(0, candidates.size(), {}, candidates, 0, target, st);
        return st;
    }
};