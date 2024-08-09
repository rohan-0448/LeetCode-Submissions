class Solution {
public:

    bool check(vector<vector<int>>& grid, int x, int y){
        set<int> st;
        int sum = 1+2+3+4+5+6+7+8+9, curr = 0;
        for(int i=x; i<x+3; i++) {
            for(int j=y; j<y+3; j++) {
                if(grid[i][j] > 9) return false;
                curr += grid[i][j];
                st.insert(grid[i][j]);
            }
        }


        int r1 = grid[x][y] + grid[x][y+1] + grid[x][y+2];
        int r2 = grid[x+1][y] + grid[x+1][y+1] + grid[x+1][y+2];
        int r3 = grid[x+2][y] + grid[x+2][y+1] + grid[x+2][y+2];
        int c1 = grid[x][y] + grid[x+1][y] + grid[x+2][y];
        int c2 = grid[x][y+1] + grid[x+1][y+1] + grid[x+2][y+1];
        int c3 = grid[x][y+2] + grid[x+1][y+2] + grid[x+2][y+2];
        int d1 = grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2];
        int d2 = grid[x+2][y] + grid[x+1][y+1] + grid[x][y+2];

        if(r1 == r2 && r2 == r3 && r3 == c1 && c1 == c2 && c2 == c3 && c3 == d1 && d1 == d2 && sum == curr && st.size()==9) return true;

        return false;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3 || grid[0].size()<3) return 0;

        int cnt = 0;
        for(int i=0; i<grid.size()-2; i++) for(int j=0; j<grid[0].size()-2; j++) if(check(grid, i, j)) cnt++;

        return cnt;
        
        // int sum = 1+2+3+4+5+6+7+8+9, curr = 0;
        // for(int i=0; i<3; i++) for(int j=0; j<3; j++) curr += grid[i][j];

        // int cnt = (curr == sum)? 1: 0;
        // for(int j=0; j<grid[0].size()-2; j++){
        //     for(int i=3; i<grid.size(); i++){
        //         curr -= (grid[i-3][j] + grid[i-3][j+1] + grid[i-3][j+2]);
        //         curr += (grid[i][j] + grid[i][j+1] + grid[i][j+2]);

        //         if(curr == sum) cnt++;
        //     }
        // }

        // return cnt;
    }
};