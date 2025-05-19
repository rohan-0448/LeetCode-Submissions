class Solution {
public:
    // bool dfs(int src, vector<vector<int>> &graph, vector<int> &visited, vector<int> &path_vis, vector<int> &check){
    //     visited[src] = 1;
    //     path_vis[src] = 1;
    //     check[src] = -1;

    //     for(auto it: graph[src]){
    //         if(visited[it] == -1) {
    //             if (dfs(it, graph, visited, path_vis, check)) {
    //                 return true;
            
    //         }
    //         else if(path_vis[it] == 1) return true;
    //     }

    //     check[src] = 1;
    //     path_vis[src] = -1;
    //     return false;
    // }

    vector<int> eventualSafeNodes(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> adj(n, vector<int> (0, 0));
        vector<int> indegree(n, 0);

        for(int i=0; i<n; i++){
            for(auto it: grid[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;
        for(int i=0; i<n; i++) if(indegree[i] == 0) q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};