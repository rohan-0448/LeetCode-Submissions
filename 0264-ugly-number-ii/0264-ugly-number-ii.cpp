class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> t(n + 1);
        t[1] = 1; 

        int t2=1, t3=1, t5=1;
        for(int i=2; i<=n; i++) {
            t[i] = min({t[t2]*2, t[t3]*3, t[t5]*5});

            if (t[i] == t[t2]*2) t2++;
            if (t[i] == t[t3]*3) t3++;
            if (t[i] == t[t5]*5) t5++;
        }
        return t[n];
    }
};