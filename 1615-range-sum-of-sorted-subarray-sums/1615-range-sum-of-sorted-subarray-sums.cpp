class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> vec;
        int mod = 1e9+7;
        for(int i=0; i<n; i++){
            long long sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                vec.push_back(sum % mod);
            }
        }
        sort(vec.begin(), vec.end());
        
        int total = 0;
        for(int i=left-1; i<right; i++) total = (total+(vec[i]%mod))%mod;
        
        return total;
    }
};