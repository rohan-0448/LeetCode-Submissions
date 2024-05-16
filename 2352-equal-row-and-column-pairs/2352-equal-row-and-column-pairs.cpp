class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rowMap, colMap;
        
        for(int i=0; i<grid.size(); i++) rowMap[grid[i]]++;
        
        for(int j=0; j<grid.size(); j++) {
            vector<int> col;
            for(int i=0; i<grid.size(); i++) col.push_back(grid[i][j]);
            colMap[col]++;
        }
        
        int count = 0;
        for(const auto& row : rowMap) if(colMap.find(row.first) != colMap.end()) count += row.second * colMap[row.first];
        
        return count;
    }
};