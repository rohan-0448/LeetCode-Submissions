class Solution {
public:

    void fill(vector<vector<int>>& matrix, int i, int j){
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j]==1) return;

        matrix[i][j] = 1;

        fill(matrix, i+1, j);
        fill(matrix, i, j+1);
        fill(matrix, i-1, j);
        fill(matrix, i, j-1);
    }

    int regionsBySlashes(vector<string>& grid) {
        int r = grid.size(), c = grid[0].size(), cnt = 0;

        vector<vector<int>> matrix(r*3, vector<int>(c*3, 0));

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == '/'){
                    matrix[i*3][j*3+2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                }
                else if(grid[i][j] == '\\'){
                    matrix[i*3][j*3] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3+2] = 1;
                }
            }
        }

        for(int i=0; i<r*3; i++){
            for(int j=0; j<c*3; j++){
                if(matrix[i][j] == 0){
                    fill(matrix, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};