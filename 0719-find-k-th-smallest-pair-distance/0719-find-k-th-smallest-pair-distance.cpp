class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = *max_element(nums.begin(), nums.end());
        vector<int> vec(n+1, 0);

        for(int i=0; i<nums.size(); i++) for(int j=i+1; j<nums.size(); j++) vec[abs(nums[i]-nums[j])]++;

        for(int i=0; i<=n; i++) {
            k -= vec[i];
            if(k<=0) return i;
        }
        return -1;
    }
};