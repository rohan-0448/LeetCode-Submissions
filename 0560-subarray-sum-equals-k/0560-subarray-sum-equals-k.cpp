class Solution {
public:
    
    void dp(vector<int> &nums, int index, int target, int &c){
        if(index == 0) {
            if(target == nums[index]) c++;
            return;
        }
        if(target == 0){ 
            c++;
            return;
        }
        if(target < 0) return;
        
        dp(nums, index-1, target-nums[index], c);
        dp(nums, index-1, target, c);
    }
    
    int subarraySum(vector<int>& nums, int k) {
        // int c = 0;
        // dp(nums, nums.size()-1, k, c);
        // return c;
        //Prefix sum approach
        
        unordered_map<int,int> mp; // prefixsum and frequency map 
        int count = 0 , sum = 0; // initialise counter and sum with 0
        mp[sum] = 1; // we will put 1 in the map first
        
        for(auto i : nums){
            sum += i; //calculate the prefix sum 
            if(mp.find(sum - k) != mp.end()) count += mp[sum - k]; // we using this case X + (X - k) = k
            mp[sum]++;
        }
        return count;
    }
};