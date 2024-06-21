class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> vec(n);
        for(int i=0; i<n; i++) vec[i] = {capital[i], profits[i]};

        sort(vec.begin(), vec.end());

        priority_queue<int> pq;

        int ind = 0;
        while(k--){
            while(ind<n && w >= vec[ind].first){
                pq.push(vec[ind].second);
                ind++;
            }
            if(!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
            else break;
        }
        return w;
    }
};