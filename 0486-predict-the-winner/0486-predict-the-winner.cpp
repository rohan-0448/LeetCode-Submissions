class Solution {
public:
    bool recursive(vector<int> &nums, int score, int left, int right, bool flag) {
        if(left > right) return (score >= 0);
        // if flag == true - we add to score
        // if flag == false - we subtract

        bool l = false, r = false, ans = false;
        if(flag) {
            // take left
            l = recursive(nums, score+nums[left], left+1, right, !flag);
            
            // take right
            r = recursive(nums, score+nums[right], left, right-1, !flag);

            ans = l || r;
        }

        else {
            // take left
            l = recursive(nums, score-nums[left], left+1, right, !flag);
            
            // take right
            r = recursive(nums, score-nums[right], left, right-1, !flag);

            ans = l && r;
        }

        return ans;
    }

    bool predictTheWinner(vector<int>& nums) {
        return recursive(nums, 0, 0, nums.size()-1, true);
    }
};