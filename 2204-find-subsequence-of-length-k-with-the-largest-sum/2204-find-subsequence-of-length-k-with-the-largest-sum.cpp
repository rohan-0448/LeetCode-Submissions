class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> nums1;
        for(int i = 0; i < nums.size(); i++) 
            nums1.push_back({nums[i], i});

        // Sort by value descending
        sort(nums1.begin(), nums1.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        // Take top k elements' indices
        vector<int> indices;
        for(int i = 0; i < k; i++) 
            indices.push_back(nums1[i].second);

        // Sort indices to maintain original order
        sort(indices.begin(), indices.end());

        // Collect values in original order
        vector<int> result;
        for(int i : indices) 
            result.push_back(nums[i]);

        return result;
    }
};
