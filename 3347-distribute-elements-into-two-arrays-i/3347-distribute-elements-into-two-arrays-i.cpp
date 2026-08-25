class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;

        int n = nums.size(), curr = 0;
        if(curr < n) arr1.push_back(nums[curr]);
        curr++;

        if(curr < n) arr2.push_back(nums[curr]);
        curr++;

        while(curr < n) {
            if(arr1.back() > arr2.back()) arr1.push_back(nums[curr]);
            else arr2.push_back(nums[curr]);

            curr++;
        }

        for(auto &i: arr2) arr1.push_back(i);

        return arr1;
    }
};