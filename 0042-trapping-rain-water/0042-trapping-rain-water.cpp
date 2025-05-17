class Solution {
public:
    int trap(vector<int>& nums) {
        int ind = -1, mx = INT_MIN, n = nums.size(), val = INT_MIN, sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > mx){
                mx = nums[i];
                ind = i;
            }
        }

        for(int i = 0; i<ind; i++){
            val = max(val, min(nums[i], nums[ind]));
            if(i!=0) sum += (val-nums[i]);
        }
        val = INT_MIN;
        for(int i=n-1; i>ind; i--){
            val = max(val, min(nums[i], nums[ind]));
            if(i!=n-1) sum += (val-nums[i]);
        }

        return sum;
        // int start = 0, end = 0, sum = 0;
        // for(int i=1; i<nums.size()-1; i++){
        //     if(nums[i] > nums[i+1]){
        //         // while(nums[i] > nums[i+1]) i++;
        //         start = i;
        //         i++;
        //         while(nums[i] > nums[i+1]) i++;
        //         end = i;

        //         int val = min(nums[start], nums[end]);
        //         cout << start << "-" << end << "--" << val << endl;
        //         for(int j=start+1; j<end; j++){
        //             sum += (val-nums[j]);
        //             nums[j] = val;
        //         }
        //         i--;
        //     }
        // }
        // for(auto i: nums) cout << i << ", ";
        // cout << endl;
        // return sum;
    }
};