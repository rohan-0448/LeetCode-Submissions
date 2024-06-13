class Solution {
public:

    // int check(vector<int>&nums, int tar, int index, int sum){
    //     if(index == nums.size()){
    //         if (sum % tar == 0 && sum != 0) return 1;
    //         else return 0;
    //     }

    //     int take = check(nums, tar, index+1, sum+nums[index]);
    //     int not_take = check(nums, tar, index+1, sum);

    //     return take + not_take;
    // }

    int subarraysDivByK(vector<int>& nums, int k) {
        // return check(nums, k, 0, 0);
        int presum = 0, ans = 0;
        unordered_map<int, int> mp{{0,1}};
        for(int i=0; i<nums.size(); i++){
            presum += (nums[i]%k + k);
            presum %= k;
            ans += mp[presum];
            mp[presum]+=1;
            // cout << nums[i] << " presum-" << presum << " ans-"<< ans << endl;
            // for(auto i: mp) cout << i.first << "-" << i.second << ", ";
            // cout << endl;
        }
        return ans;
    }
};