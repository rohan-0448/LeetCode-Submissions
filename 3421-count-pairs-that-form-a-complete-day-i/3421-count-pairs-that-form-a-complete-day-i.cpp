class Solution {
public:
    int countCompleteDayPairs(vector<int>& vec) {
        sort(vec.begin(), vec.end());
        int c = 0, n = vec.size();
        for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) if((vec[i]+vec[j])%24 == 0) c++;
        return c;
    }
};