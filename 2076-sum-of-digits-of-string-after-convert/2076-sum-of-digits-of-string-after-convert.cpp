class Solution {
public:
    int getLucky(string s, int k) {
        int val = 0;
        string temp = s;
        for(auto i: temp) {
            int x = abs(i-'a'+1);
            while(x){
                val+=x%10;
                x/=10;
            }
        }
        cout << val << endl;
        int ans = val;
        while(k>1){
            ans = 0;
            while(val){
                ans += val%10;
                val /= 10;
            }
            val = ans;
            k--;
        }

        return ans;
    }
};