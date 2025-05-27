class Solution {
public:
    void recursive(int index, string s, vector<string> curr, vector<vector<string>> &ans) {
        if(index == s.length()) {
            ans.push_back(curr);
            return;
        }

        for(int i=index; i<s.length(); i++) {
            string sub = s.substr(index, i-index+1);
            if(check_palin(sub)) {
                curr.push_back(sub);
                recursive(i+1, s, curr, ans);
                curr.pop_back();
            }
        }
    }

    bool check_palin(string s) {
        int i = 0, j = s.length()-1;

        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;

        recursive(0, s, {}, ans);

        return ans;
    }
};