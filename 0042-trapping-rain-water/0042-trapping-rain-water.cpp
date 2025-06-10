class Solution {
public:
    int trap(vector<int>& nums) {
        int ind = -1, mx = INT_MIN, n = nums.size(), val = INT_MIN, sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > mx){
                mx = nums[i]; // found max element
                ind = i; // found max element index
            }
        }

        for(int i = 0; i<ind; i++){ // 0 till mx index
            val = max(val, nums[i]); // check if there is some left side wall we can use
            if(i!=0) sum += (val-nums[i]); // add the diff in wall and curr hgt
        }
        val = INT_MIN;
        for(int i=n-1; i>ind; i--){ // n-1 till mx index
            val = max(val, nums[i]);
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