class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n+1); // node, time
        for(auto iter: times){ // directed graph
            adjList[iter[0]].push_back({iter[1], iter[2]});
        }

        vector<int> distance(n+1, INT_MAX);
        distance[k] = 0;
        distance[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.push({0, k}); // time, node

        while(!min_heap.empty()){
            auto it = min_heap.top(); min_heap.pop();
            int time = it.first, node = it.second;

            for(auto iter: adjList[node]){
                int adjNode = iter.first, adjWt = iter.second;
                if(distance[adjNode] > time + adjWt){
                    distance[adjNode] = time + adjWt;
                    min_heap.push({time + adjWt, adjNode});
                }
            }
        }
        
        int mx = 0;
        for(auto i: distance) {
            if(i == INT_MAX) return -1;
            else mx = max(mx, i);
        }
        return mx;
    }
};