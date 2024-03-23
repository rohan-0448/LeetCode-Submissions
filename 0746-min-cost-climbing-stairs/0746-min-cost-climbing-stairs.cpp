// class Solution {
// public:

//     static int check(vector<int> &dp, vector<int> &cost, int index){
//         if(index == 0) return cost[0];
//         if(index == -1) return 0;

//         if(dp[index]!=-1) return dp[index];

//         int first = check(dp, cost, index-1) + cost[index-1];
//         int second = INT_MAX;
//         if(index>0) second = (index-2==-1)? check(dp, cost, index-2): check(dp, cost, index-2) + cost[index-2];

//         return dp[index] = min(first, second);
//     }

//     int minCostClimbingStairs(vector<int>& cost) {
//         vector<int> dp(cost.size()+1, -1);
//         dp[0] = cost[0];
//         return check(dp, cost, cost.size()-1);
//     }
// };

class Solution {
public:

    static int check(vector<int> &dp, vector<int> &cost, int index) {
        // Correct base case handling
        if (index <= 1) return 0;

        // Check if the result is already computed
        if (dp[index] != -1) return dp[index];

        // Calculate cost to step onto this stair from two possible previous positions
        int costToStepHereFromOneStepBack = check(dp, cost, index - 1) + cost[index - 1];
        int costToStepHereFromTwoStepsBack = check(dp, cost, index - 2) + cost[index - 2];

        // Store the minimum of the two possibilities
        dp[index] = min(costToStepHereFromOneStepBack, costToStepHereFromTwoStepsBack);
        return dp[index];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, -1); // Use cost.size() + 1 for dp to include the "step over the top" scenario
        // Compute the minimum cost from either starting point (0 or 1) to "step over the top"
        return check(dp, cost, cost.size());
    }
};
