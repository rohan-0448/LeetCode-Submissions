class Solution {
public:
    long long minimumSteps(string s) {
        long long ones=0, res=0, n=s.length();
        
        for(long long j=0; j<n; j++) {
            if(s[j] == '0') res += ones;
            else if(s[j] == '1') ones++;
        }
        
        return res;
    }
};