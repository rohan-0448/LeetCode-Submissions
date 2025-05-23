class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int src = 0, dst = n-1, MOD = 1e9 + 7;
        
        vector<vector<pair<int, int>>> adjList(n);
        for(auto iter : roads){
            adjList[iter[0]].push_back({iter[1], iter[2]});
            adjList[iter[1]].push_back({iter[0], iter[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0}); // distance, node

        vector<int> ways(n, 0);
        ways[0] = 1;
        vector<long long> distance(n, LONG_MAX);
        distance[0] = 0;

        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int node = it.second;
            long long dist = it.first;

            // if(node == dst) continue;

            for(auto adjNode : adjList[node]){
                long long curr = adjNode.first, wgt = adjNode.second;
                if(dist + wgt < distance[curr]){
                    distance[curr] = dist + wgt;
                    pq.push({dist + wgt, curr});
                    ways[curr] = ways[node] % MOD;
                }
                else if(dist + wgt == distance[curr]) ways[curr] = (ways[curr] + ways[node]) % MOD;
            }
        }

        return ways[n-1];
    }
};