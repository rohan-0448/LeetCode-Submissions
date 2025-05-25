class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
        size.resize(n, 1);
    }
    
    int find_ultimate_parent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = find_ultimate_parent(parent[node]);
    }
    
    void union_by_size(int a, int b) {
        int ult_a = find_ultimate_parent(a);
        int ult_b = find_ultimate_parent(b);
        
        if(ult_a == ult_b) return;
        
        if(size[ult_a] < size[ult_b]) {
            parent[ult_a] = ult_b;
            size[ult_b] += size[ult_a];
        }
        else {
            parent[ult_b] = ult_a;
            size[ult_a] += size[ult_b];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        DisjointSet ds(rows * cols);

        vector<int> dr = {0, 0, -1, 1};
        vector<int> dc = {1, -1, 0, 0};
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {                
                if (grid[row][col] == 0) continue;
                
                for(int i = 0; i <4 ; i++) {
                    int adjR = row + dr[i];
                    int adjC = col + dc[i];
                    

                    if(adjR < rows && adjR >= 0 && adjC < cols && adjC >= 0 && grid[adjR][adjC] == 1) {
                        int node = row * cols + col;
                        int adjNode = adjR * cols + adjC;

                        ds.union_by_size(node, adjNode);
                    }
                }
            }   
        }

        int mx = 0, one = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    one = 1;
                    continue;
                }

                set<int> st;
                for(int k = 0; k < 4 ; k++) {
                    int adjR = i + dr[k];
                    int adjC = j + dc[k];

                    if(adjR < rows && adjR >= 0 && adjC < cols && adjC >= 0 && grid[adjR][adjC] == 1) {
                        st.insert(ds.find_ultimate_parent(adjR * cols + adjC));
                    }
                }
                int curr_size = 1;
                for(auto i: st) {
                    curr_size += ds.size[i];
                }

                mx = max(mx, curr_size);
            }
        }

        for(int i = 0; i < rows * cols; i++) mx = max(mx, ds.size[ds.find_ultimate_parent(i)]);

        if(one == 0) return 1;
        return mx;
    }
};