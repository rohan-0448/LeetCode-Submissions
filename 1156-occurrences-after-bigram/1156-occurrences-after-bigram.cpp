class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;

        string s;

        stringstream ss(text);

        while (getline(ss, s, ' ')) {
            res.push_back(s);
        }

        int n = res.size();
        vector<string> ans;
        for (int i = 0; i <= n - 3; i++) {
            if (res[i] == first && res[i + 1] == second) {
                ans.push_back(res[i + 2]);
            }
        }

        return ans;
    }
};