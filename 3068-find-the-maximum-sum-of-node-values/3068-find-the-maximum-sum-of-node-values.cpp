class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0, cnt = 0, temp = INT_MAX;
        for (auto n : nums) {
            sum += max(n^k, n);
            if((n^k) > n) cnt++;
            if(abs(n-(n^k)) < temp) temp = abs(n-(n^k)); 
        }
        if(cnt%2) sum -= temp;
        return sum;
    }
};