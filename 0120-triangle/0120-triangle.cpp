class Solution {
public:
    int min_sum(int x, int y, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(x == triangle.size()-1) return triangle[x][y];
        if(dp[x][y] != -1) return dp[x][y];

        return dp[x][y] = triangle[x][y] + min(min_sum(x+1, y, triangle, dp), min_sum(x+1, y+1, triangle, dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return min_sum(0, 0, triangle, dp);
    }
};