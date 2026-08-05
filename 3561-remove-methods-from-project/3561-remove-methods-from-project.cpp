class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<int> &vis) {
        vis[node] = 1;
        for(auto &it: adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;

        for(auto &it: invocations) {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> vis(n, 0);
        dfs(k, adj, vis);

        vector<int> ans;

        for(auto &it: invocations) {
            if(vis[it[0]] == false && vis[it[1]] == true) {
                for(int i=0; i<n; i++) ans.push_back(i);
                return ans;
            }
        }

        for(int i=0; i<n; i++) if(!vis[i]) ans.push_back(i);

        return ans;
    }
};