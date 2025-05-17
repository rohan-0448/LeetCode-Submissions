class Solution {
public:

    void dfs(int src, vector<vector<int>> &adj, vector<int> &vis){
        vis[src] = 1;
        for(auto i: adj[src]){
            if(vis[i] == 0){
                dfs(i, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n, vector<int> (n, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int c = 0;
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                dfs(i, adj, vis);
                c++;
            }
        }

        return c;
    }
};