class Solution {
public:
    // Recursion with Memoization doesn't work
    int check(vector<vector<int>> &dp, vector<vector<int>> &matrix, int r, int c){
        if(r == 0) return matrix[r][c];
        if(dp[r][c] != -1) return dp[r][c];
        
        int top = INT_MAX, top_left = INT_MAX, top_right = INT_MAX;
        
        if(c == 0){
            top = matrix[r][c] + check(dp, matrix, r-1, c);
            top_right = matrix[r][c] + check(dp, matrix, r-1, c+1);
        }
        else if(c == matrix[0].size()-1){
            top = matrix[r][c] + check(dp, matrix, r-1, c);
            top_left = matrix[r][c] + check(dp, matrix, r-1, c-1);
        }
        else{
            top = matrix[r][c] + check(dp, matrix, r-1, c);
            top_right = matrix[r][c] + check(dp, matrix, r-1, c+1);
            top_left = matrix[r][c] + check(dp, matrix, r-1, c-1);
        }
        
        return dp[r][c] = min(top, min(top_left, top_right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size(), min_path = INT_MAX;
        if(r==1 && c==1) return matrix[0][0];
        vector<vector<int>> dp(r, vector<int> (c, -1));
        // Tabulation
        for(int i=0; i<c; i++){
            dp[0][i] = matrix[0][i];
        }
        
        for(int row=1; row<r; row++){
            for(int col=0; col<c; col++){
                int top = INT_MAX, top_right = INT_MAX, top_left = INT_MAX;
                // if(col == 0) {
                //     top = dp[row-1][col];
                //     top_right = dp[row-1][col+1];
                // } else if(col == c-1){
                //     top = dp[row-1][col];
                //     top_left = dp[row-1][col-1];
                // }else{
                top = dp[row-1][col];
                if(col != c-1) top_right = dp[row-1][col+1];
                if(col != 0) top_left = dp[row-1][col-1];
                // }
                dp[row][col] = matrix[row][col] + min(top, min(top_left, top_right));
                if(row == r-1) min_path = min(min_path, dp[row][col]);
            }
        }
        return min_path;
        
        for(int i=0; i<c; i++){
            min_path = min(min_path, check(dp, matrix, r-1, i));
        }
        return min_path;
    }
};