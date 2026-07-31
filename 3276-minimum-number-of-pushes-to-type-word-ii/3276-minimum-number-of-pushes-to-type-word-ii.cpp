class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for(auto &i: word) mp[i]++;

        priority_queue<int> pq;
        for(auto &[x, y]: mp) pq.push(y);
        
        int c = 0, ans = 0, p = 1;

        while(!pq.empty()) {
            ans += pq.top() * p;
            pq.pop();
            c++;
            if(c == 8) {
                p++;
                c = 0;
            }
        }

        return ans;
    }
};