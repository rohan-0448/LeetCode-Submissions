class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            auto it = find(nums.begin()+i+1, nums.end(), target - nums[i]);
            if(it != nums.end()){
                int index = it-nums.begin();
                return {i, index};
            }
        }
        return {0, 0};
        // vector<int> ans;
        // for(int i=0; i<nums.size()-1; i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(nums[i]+nums[j]==target) {
        //             cout << i << " " << j << endl;
        //             return {i, j};
        //         }
        //     }
        // }
        // return {0, 0};
        // for(int i=0; i<nums.size(); i++){
        //     auto it = find(nums.begin()+i+1, nums.end(), target - nums[i]);
        //     if(it != nums.end()){
        //         ans.push_back(i);
        //         ans.push_back(it-nums.begin());
        //         break;
        //     }
        //     // for(int j=i+1 ;j<nums.size(); j++){
        //     //     if(nums[i] + nums[j] == target){
        //     //         ans.push_back(i);
        //     //         ans.push_back(j);
        //     //         break;
        //     //     }
        //     // }
        // }

        // return ans;
    }
};