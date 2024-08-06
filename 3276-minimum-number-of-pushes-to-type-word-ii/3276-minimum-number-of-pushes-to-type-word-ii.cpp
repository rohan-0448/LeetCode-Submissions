class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        // int curr = 1, count = 1, total = 0;
        for(auto i: word){
            mp[i]++;
            // if(mp.find(i) == mp.end()) {
            //     mp[i] = curr;
            //     count++;
            // }
            // if(count == 8){
            //     count = 1;
            //     curr++;
            // }
            // total+=mp[i];
        }
        priority_queue<pair<int, char>> pq;
        for(auto i: mp) pq.push({i.second, i.first});

        int total = 0;
        int curr = 1;
        while(!pq.empty()){
            int tmp = 8;
            while(!pq.empty() && tmp--){
                int top_frq = pq.top().first;
                char top_val = pq.top().second;
                pq.pop();

                total += top_frq*curr;
                cout << top_val << "-" << total << endl;
            }
            curr++;
        }

        return total;
    }
};