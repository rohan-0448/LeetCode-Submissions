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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int> (n , 0));
        vis[0][0] = 1;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0}); // max hgt, x, y

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {-1, 1, 0, 0};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int height = it[0], x = it[1], y = it[2];

            if(x == n-1 && y == n-1) return height;

            for(int i=0; i<4; i++){
                int nx = x + dx[i], ny = y + dy[i];

                if(nx < n && nx >= 0 && ny < n && ny >= 0 && vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    pq.push({max(height, grid[nx][ny]), nx, ny});
                }
            }
        }

        return -1;
    }
};