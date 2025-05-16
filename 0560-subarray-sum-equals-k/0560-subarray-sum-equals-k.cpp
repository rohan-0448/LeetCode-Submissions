class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp; // prefixsum and frequency map 
        int count = 0 , sum = 0; // initialise counter and sum with 0
        mp[sum] = 1;
        
        for(auto i : nums){
            sum += i;
            if(mp.find(sum - k) != mp.end()) count += mp[sum - k];
            mp[sum]++;
        }
        return count;
    }
};