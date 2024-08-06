class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for(auto i: word) mp[i]++;

        priority_queue<pair<int, char>> pq;
        for(auto i: mp) pq.push({i.second, i.first});

        int total = 0, curr = 1;
        while(!pq.empty()){
            int tmp = 8;
            while(!pq.empty() && tmp--){
                int top_frq = pq.top().first;
                pq.pop();

                total += top_frq*curr;
            }
            curr++;
        }

        return total;
    }
};