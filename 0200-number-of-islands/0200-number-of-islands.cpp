class Solution {
public:
    
    void change(vector<vector<char>> &grid, int x, int y){
        grid[x][y] = '0';
        if(x!=0 && grid[x-1][y] == '1') change(grid, x-1, y);
        if(x!=grid.size()-1 && grid[x+1][y] == '1') change(grid, x+1, y);
        if(y!=0 && grid[x][y-1] == '1') change(grid, x, y-1);
        if(y!=grid[x].size()-1 && grid[x][y+1] == '1') change(grid, x, y+1);
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int c = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == '1') {
                    change(grid, i, j);
                    c++;
                }
            }
        }
        return c;
    }
};