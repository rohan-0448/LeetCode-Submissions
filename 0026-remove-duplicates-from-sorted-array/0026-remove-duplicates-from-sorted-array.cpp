class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), i, j;
        if(n == 1) return 1;

        for(i=1, j=1; j<n; j++) if(nums[i-1]!=nums[j]) nums[i++] = nums[j];
        return i;
    }
        // if(nums.size()==1) return 1;
        // for(int i=0 ;i<nums.size()-1; i++){
        //     if(nums[i] == nums[i+1]){
        //         int x = 1;
        //         while(nums[i] == nums[i+x] && i+x < nums.size()){
        //             nums[i+x] = INT_MAX;
        //             x++;
        //         }
        //         // i+=x-1;
        //     }
        // }
        // // for(int i=0; i<nums.size(); i++) cout << nums[i] << " ";
        // // cout << endl;
        // sort(nums.begin(), nums.end());
        // // for(int i=0; i<nums.size(); i++) cout << nums[i] << " ";
        // // cout << endl;
        // int y = 0;
        // while(nums[y]!=INT_MAX && y<nums.size()) y++;

        // cout << y;
        // return y;
    // }
    // int removeDuplicates(vector<int>& nums) {
    //     set<int> s;
    //     for(auto i: nums){
    //         s.insert(i);
    //     }

    //     int index = 0;
    //     for(auto i: s){
    //         nums[index++] = i;
    //     }

    //     return s.size();
    // }
};