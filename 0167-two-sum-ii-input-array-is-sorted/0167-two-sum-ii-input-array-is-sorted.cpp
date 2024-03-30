class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0, right=numbers.size()-1;
        while(left<=right){
            int try_tg=numbers[left]+numbers[right];

            if(try_tg==target) return {left+1, right+1};
            else if(try_tg>target) right--;
            else left++;
        }
        return {};
    }
};