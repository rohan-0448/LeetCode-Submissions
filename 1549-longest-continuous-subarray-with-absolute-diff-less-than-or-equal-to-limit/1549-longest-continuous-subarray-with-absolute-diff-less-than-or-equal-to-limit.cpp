class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), ml = 1;
        for(int i=0; i<n; i++){
            int mn = nums[i], mx = nums[i], tmp = i+1;
            while(tmp<n && mx-mn <= limit){
                mx = max(mx, nums[tmp]);
                mn = min(mn, nums[tmp]);
                if(mx-mn > limit) break;
                tmp++;
            }
            cout << i << "-" << tmp << endl;
            ml = max(ml, tmp-i);
            while(i<n-1 && nums[i] == nums[i+1]) i++;
        }
        return ml;
    }
};