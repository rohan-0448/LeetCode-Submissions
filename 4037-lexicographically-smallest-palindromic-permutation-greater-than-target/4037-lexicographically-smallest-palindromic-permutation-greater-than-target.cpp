class Solution {
public:
    string mid = "";
    int halflen = 0;
    string result = "";

    bool solve(string &curr, vector<int> &count, string &target, int i, bool greater) {
        if(curr.length() == halflen) {
            string left = curr, right = curr;
            reverse(right.begin(), right.end());

            string cand = left + mid + right;

            if(cand > target) {
                result = cand;
                return true;
            }

            return false;
        }

        for(char ch='a'; ch<='z'; ch++) {
            if(count[ch-'a'] == 0) continue;
            if(!greater && ch<target[i]) continue;

            curr.push_back(ch);
            count[ch-'a']--;

            bool isGreater = (greater || ch > target[i]); 

            if(solve(curr, count, target, i+1, isGreater)) return true;

            curr.pop_back();
            count[ch-'a']++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);

        for(auto &i: s) count[i-'a']++;

        int oddCount = 0;
        for(int i=0; i<26; i++) {
            if(count[i] % 2 == 1) {
                oddCount++;
                mid = 'a'+i;
            }
        }   

        if(oddCount > 1) return "";

        for(int i=0; i<26; i++) count[i] /= 2;
        halflen = n/2;
        string curr;

        solve(curr, count, target, 0,  false);

        return result;
    }
};