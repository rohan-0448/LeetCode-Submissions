class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mp;
        for(auto i: tasks) mp[i]++;
        priority_queue<int> max_heap;
        for(auto i: mp) max_heap.push(i.second);

        queue<pair<int, int>> q;
        int time = 0;
        while(!(max_heap.empty() && q.empty())){
            time++;
            if(!max_heap.empty()){
                int freq = max_heap.top()-1;
                max_heap.pop();
                if(freq>0) q.push({time+n, freq});
            }
            if(!q.empty() && q.front().first == time) {
                max_heap.push(q.front().second);
                q.pop();
            }
            // if(max_heap.empty() && !q.empty()) time = q.front().first;
        }
        return time;
    }
};