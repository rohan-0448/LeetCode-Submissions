class Solution {
public:
    static bool canChange(string& s, string& t) {
        const int n=s.size();
        for(int i=0, j=0; i<n || j<n; i++, j++){
            while(i<n && s[i]=='_') i++;
            while(j<n && t[j]=='_') j++;
            
            if (s[i] !=t[j] || (s[i] =='L' && i<j) || (s[i] =='R' && i>j)) return 0;
        }
        return 1;
    }
};