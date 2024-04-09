class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int val = tickets[k], tot = 0;
        for(int i=0; i<tickets.size(); i++){
            if(i<=k) tot += min(val, tickets[i]);
            else tot += min(val, tickets[i]);
        }
        for(int i=k+1; i<tickets.size(); i++) if(tickets[i] >= val) tot--;
        return tot;
            // if(i > k-1 && tickets[i] > tickets[k-1]) tot -= tickets[k-1] - tickets[i];
        // for(int i=0; i<=k; i++){
        //     tickets[i] = min(0, tickets[i]-1);
        // }
        // int ext = accumulate(tickets.begin(), tickets.end(), 0);
        // return tot-ext;
        // int x = tickets[k-1]-1, sum = 0;
        // for(int i=0; i<tickets.size(); i++){
        //     sum += min(tickets[i]-1, x);
        // }
        // for(int i=0; i<k; i++){
        //     sum += (tickets[i] >= x)? 1: 0;
        // }
        // return sum;
    }
};