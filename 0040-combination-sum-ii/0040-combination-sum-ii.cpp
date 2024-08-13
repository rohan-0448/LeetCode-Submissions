class Solution {
public:

    void check(vector<int>& vals, int index, int tar, int curr, vector<int>& temp, vector<vector<int>>& ans){
        if(index > vals.size() || curr > tar) return;
        if(tar == curr) ans.push_back(temp);

        for(int i=index; i<vals.size(); i++) {
            if (i>index && vals[i]==vals[i-1]) continue;
            if (curr + vals[i] > tar) break;
            
            temp.push_back(vals[i]);            
            check(vals, i + 1, tar, curr + vals[i], temp, ans);
            temp.pop_back();
        }

        // if(index != vals.size() && curr+vals[index] <= tar) {
        //     temp.push_back(vals[index]);
        //     check(vals, index+1, tar, curr+vals[index], temp, ans);
        //     temp.pop_back();
        // }

        // check(vals, index+1, tar, curr, temp, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(candidates.begin(), candidates.end());
        check(candidates, 0, target, 0, temp, ans);
        
        return ans;
    }
};