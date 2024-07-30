class Solution {
public:
    int minimumDeletions(string s) {
        int count_a = 0;
        for(auto i: s) if(i=='a') count_a++;

        int mn = count_a, count_b = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'b') count_b++;
            if(s[i] == 'a') count_a--;

            int curr = count_a + count_b;

            mn = min(curr, mn);
        }

        return mn;
    }
};