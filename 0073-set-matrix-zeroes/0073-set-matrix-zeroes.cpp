class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) { 
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        
        vector<pair<int, int>> coords;
        for(int row=0; row<matrix.size(); row++) for(int col=0; col<matrix[row].size(); col++) if(matrix[row][col]==0) coords.push_back({row, col});
        
        for(auto [row, col]: coords){
            for(int r2=row, c2=0; c2<matrix[row].size(); c2++) matrix[r2][c2] = 0;
            for(int r3=0, c3=col; r3<matrix.size(); r3++) matrix[r3][c3] = 0;
        }
        return;
    }
};