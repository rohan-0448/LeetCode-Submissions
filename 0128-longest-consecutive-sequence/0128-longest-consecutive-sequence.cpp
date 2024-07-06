class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;

        unordered_set<int> s(nums.begin(), nums.end()); 
        vector<int> v(s.begin(), s.end());
        sort(v.begin(), v.end());

        int left = 0, right = 1, mx = 0;
        while(right<v.size()){
            if(v[right] == v[right-1]+1) right++;
            else {
                mx = max(mx, right-left);
                left = right;
                right++;
            }
        }
        return max(mx, right-left);
    }
};