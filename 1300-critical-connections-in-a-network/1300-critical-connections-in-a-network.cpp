class Solution {
    int timer = 0;
    vector<vector<int>> bridges;

    void dfs(vector<int> adj[], int node, int parent, vector<int>& visited, int time[], int low[]){
        visited[node] = 1;
        low[node] = time[node] = timer;
        timer++;

        for(auto it: adj[node]){
            if(it == parent) continue;
            if(visited[it] == 0){
                dfs(adj, it, node, visited, time, low);
                low[node] = min(low[node], low[it]);
                if(time[node] < low[it]) bridges.push_back({node, it});
            }
            else low[node] = min(low[node], low[it]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        bridges.clear();

        // Build the adjacency list
        vector<int> adj[n];
        for (auto& it : connections)
        {
            int i = it[0];
            int j = it[1];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        // Arrays for DFS and low-link values
        vector<int> visited(n, 0);
        int time[n];  
        int low[n];   

        dfs(adj, 0, -1, visited, time, low);

        return bridges;
    }
};