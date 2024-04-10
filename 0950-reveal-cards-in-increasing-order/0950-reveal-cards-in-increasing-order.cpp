class Solution {
public:

void print_queue(queue<int> q)
{
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front()<<" ";
        temp.pop();
    }
    cout << '\n';
}

    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size(), index = 0;
        vector<int> ans(n,0);
        queue<int> q;
        for(int i=0; i<n; i++) q.push(i);
        while(!q.empty()){
            // for(auto i: ans) cout << i << " ";
            // cout << endl;
            ans[q.front()] = deck[index++];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};