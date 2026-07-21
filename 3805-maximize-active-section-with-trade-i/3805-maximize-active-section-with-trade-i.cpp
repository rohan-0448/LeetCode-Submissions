class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        int count_one = count(s.begin(), s.end(), '1');

        vector<int> count_zero;
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0') i++;

                count_zero.push_back(i-start);
            }
            else i++;
        }

        int mx_pair = 0;
        for (int i = 1; i < count_zero.size(); i++) {
            mx_pair = max(mx_pair, count_zero[i-1] + count_zero[i]);
        }

        return mx_pair + count_one;
    }
};