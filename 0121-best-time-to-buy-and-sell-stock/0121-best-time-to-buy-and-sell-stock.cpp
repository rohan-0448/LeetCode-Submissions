class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_v = 0, min_v = prices[0];
        for(int i=1; i<prices.size(); i++){
            if(prices[i] < min_v) min_v = prices[i];
            else {
                int temp = prices[i]-min_v;
                if(temp > max_v) max_v = temp;
            }
        }
        return max_v;
    }
};