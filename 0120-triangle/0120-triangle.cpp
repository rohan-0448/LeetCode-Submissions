class Solution {
public:
    
    // Recursion with Memoization
    int f(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp){
        if(i == triangle.size()-1) return triangle[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + f(i+1, j, triangle, dp);
        int diagonal = triangle[i][j] + f(i+1, j+1, triangle, dp);
        
        return dp[i][j] = min(down, diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // Tabulation Method try-2
        for(int j = 0; j < n; j++) dp[n-1][j] = triangle[n-1][j];

        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
        
//         // Tabulation Method
//         int min_l = INT_MAX;
//         dp[0][0] = triangle[0][0];
//         for(int i = 1; i < n; i++){
//             for(int j = 0; j < i; j++){
//                 int top = INT_MAX, top_left = INT_MAX;
//                 if(dp[i-1][j] != -1) top = dp[i-1][j];                
//                 if(dp[i-1][j-1] != -1) top_left = dp[i-1][j-1];
                
//                 dp[i][j] = triangle[i][j];
//                 if(top != INT_MAX || top_left != INT_MAX) dp[i][j] += min(top, top_left);                
        
//                 if(i == n-1) min_l = min(min_l, dp[i][j]);
//             }
//         }
//         return min_l;
        return f(0, 0, triangle, dp);
    }
};