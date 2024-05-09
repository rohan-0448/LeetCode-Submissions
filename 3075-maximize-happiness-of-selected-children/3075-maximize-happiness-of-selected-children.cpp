class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        reverse(happiness.begin(), happiness.end());
        
        long long sum = 0;
        for(int i=0; i<k; i++) if(happiness[i]-i > 0) sum += happiness[i]-i;

        return sum;
    }
};