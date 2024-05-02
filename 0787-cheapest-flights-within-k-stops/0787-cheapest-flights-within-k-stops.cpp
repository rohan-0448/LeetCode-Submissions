class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for(auto f : flights) adjList[f[0]].push_back({f[1], f[2]});

        vector<vector<int>> dp(n, vector<int>(K+2, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, src, K+1});

        while(!minHeap.empty()) {
            auto t = minHeap.top(); minHeap.pop();
            int cost = t[0], curr = t[1], stop = t[2];
            if(curr == dst) return cost;

            if(stop > 0 && cost < dp[curr][stop]) {
                dp[curr][stop] = cost;
                for(auto next : adjList[curr]) {
                    if(cost + next.second < dp[next.first][stop-1])
                        minHeap.push({cost + next.second, next.first, stop-1});
                }
            }
        }

        return -1;
    }
};