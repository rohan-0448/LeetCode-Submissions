class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), len = accumulate(nums.begin(), nums.end(), 0);
        if(n == len) return 0;

        int count_0 = 0, l = 0, r = 0;
        for(r=0; r<len; r++) if(nums[r]==0) count_0++;

        int mn = count_0, t = n + r;
        for(; r<t; r++, l++){
            if(nums[r%n] == 0) count_0++;
            if(nums[l%n] == 0) count_0--;
            mn = min(mn, count_0);
        }

        return mn;
        // int mx = 0, n = nums.size();
        // for(int i=0; i<n-1; i++){
        //     int c = 1;
        //     while(nums[i] == nums[i+1] && nums[i] == 1){
        //         c++;
        //         i++;
        //         mx = max(mx, c);
        //     }
        // }
        // cout << mx << endl;
        
        // int i = 0, j = 0;
        // while(i < n && nums[i] == 1) i++;
        // while(n-j-1 > i && j < n  && nums[n-j-1] == 1) j++;

        // mx = max(mx, i+j);
        // cout << mx << endl;

        // return accumulate(nums.begin(), nums.end(), 0) - mx;
    }
};