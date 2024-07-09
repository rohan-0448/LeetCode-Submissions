class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_v = INT_MIN, min_v = INT_MAX, max_p = 0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i] < min_v) min_v = prices[i];
            else {
                int temp = prices[i] - min_v;
                if(temp > max_p){
                    max_p = temp;
                } 
            }
        }
        return max_p;
    }
};