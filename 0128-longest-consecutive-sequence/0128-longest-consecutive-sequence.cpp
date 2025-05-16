class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return n;
        // if(n == 1) return 1;
        // set<int> st;
        sort(nums.begin(), nums.end());
        
        int mx = INT_MIN;
        for(int i=0; i<n-1; i++){
            int cnt = 1;
            if(nums[i+1] == nums[i]+1 || nums[i+1] == nums[i]){
                while(i+1<n && (nums[i+1] == nums[i]+1 || nums[i] == nums[i+1])) {
                    if(nums[i+1] == nums[i]+1) cnt++;
                    i++;
                }
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};