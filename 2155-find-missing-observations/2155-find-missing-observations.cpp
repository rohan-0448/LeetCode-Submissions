class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int len = rolls.size(),sum = accumulate(rolls.begin(), rolls.end(), 0);
        int remaining = ((n+len)*mean)-sum;

        vector<int> ans;
        if(remaining<n || remaining>6*n) return ans;

        int base = remaining/n, extra = remaining%n;
        for(int i=0; i<n; i++) {
            if(i<extra) ans.push_back(base+1);
            else ans.push_back(base);
        }

        return ans;
    }
};
