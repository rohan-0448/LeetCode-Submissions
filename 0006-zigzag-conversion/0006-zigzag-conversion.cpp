class Solution {
public:
    string convert(string s, int n) {
        if(n==1) return s;
        string ans = "";
        int m = s.length();
        int in = (n-1)*2;
        for(int i=0; i<m; i+=in) ans += s[i];

        // cout << ans << endl;

        for(int i=1; i<n-1; i++){
            int temp = i;
            int c = (n-i-1)*2;
            while(temp<m){
                ans+=s[temp];
                if(temp+c<m) ans+=s[temp+c];
                temp+=in;
            }
            // cout << ans << endl;
        }
        for(int i=n-1; i<m; i+=in) ans += s[i];
        
        return ans;
    }
};