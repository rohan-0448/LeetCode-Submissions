class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>(0,0));
        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        vector<int> indegree(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        vector<int> topo;
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(topo.size() == numCourses) return true;
        else return false;
    }
};