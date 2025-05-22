class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({0, 0, 0}); // dist , row , col

        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        dist[0][0] = 0;

        vector<int> dx = {0, 0, -1, +1};
        vector<int> dy = {+1, -1, 0, 0};

        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            int x = tp[1], y = tp[2], diff = tp[0];
            int curr_ht = heights[x][y];
 
            // if(diff > mn) continue;

            if(x == n-1 && y == m-1) return diff;
            
            for(int i=0; i<4; i++){
                int newx = x + dx[i], newy = y + dy[i];
                if(newx < n && newx >=0 && newy < m && newy >= 0){
                    int  new_effort = max(diff, abs(curr_ht - heights[newx][newy]));
                    if(new_effort < dist[newx][newy]){
                    pq.push({new_effort, newx, newy});
                    dist[newx][newy] = new_effort;
                    }    
                }
            }
        }
        return 0;
    }
};