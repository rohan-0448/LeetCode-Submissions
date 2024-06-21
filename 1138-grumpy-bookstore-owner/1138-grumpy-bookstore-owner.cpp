class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int total = 0, n = grumpy.size();
        for(int i=0; i<n; i++) total += customers[i] * (1-grumpy[i]);

        int curr = 0;
        for(int i=0; i<minutes; i++) curr += customers[i] * grumpy[i];

        int left=0, right=minutes, maxn = curr;

        while(right < n){
            curr += customers[right] * grumpy[right++];
            curr -= customers[left] * grumpy[left++];

            maxn = max(maxn, curr);
        }
        return total + maxn;
    }
};