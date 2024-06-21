class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> parent(edges.size() + 1, 0);
        vector<int> rank(edges.size() + 1, 0);

        for (int i = 1; i <= edges.size(); ++i) {
            parent[i] = i;
        }

        function<int(int)> find = [&](int x) {
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        auto unionSets = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    ++rank[rootX];
                }
            }
        };

        for (auto& edge : edges) {
            if (find(edge[0]) == find(edge[1])) {
                return edge;
            } else {
                unionSets(edge[0], edge[1]);
            }
        }

        return {};
    }
};
