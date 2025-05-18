class Solution {
public:

    bool traverse(int start, vector<vector<int>> &graph, vector<int> &vis){
        queue<int> q;
        q.push(start);
        vis[start] = 0;

        while(!q.empty()){
            int x = q.front();
            q.pop();

            for(auto it: graph[x]){
                if(vis[it] == -1){
                    vis[it] = !vis[x];
                    q.push(it);
                }
                else if(vis[it] == vis[x]) return false;
            }
        }

        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        for(int i=0; i<n; i++) if(vis[i] == -1) if(traverse(i, graph, vis) == false) return false;
        return true;    
    }
};