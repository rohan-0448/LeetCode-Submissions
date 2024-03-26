class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> mp;
        for(auto i: nums){
            mp[i]=1;    
        }
        int n = nums.size();
        for(int i=1; i<=n; i++){
            if(mp[i]!=1) return i;
        }
        return n+1;
    }
};