class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<char> pat;
        vector<string> word;
        for(auto i: pattern) pat.push_back(i);

        int left = 0, right = 0;
        while(right<=s.length()){
            if(right == s.length() || s[right] == ' '){
                word.push_back(s.substr(left, right-left));
                left = right+1;
            }
            right++;
        }

        // for(auto i: pat) cout << i << " ";
        // cout << endl;
        // for(auto i: word) cout << i << " ";
        // cout << endl;

        if(pat.size() != word.size()) return false;

        unordered_map<char, string> mp;
        unordered_map<string, char> mp1;
        for(int i=0; i<pat.size(); i++){
            cout << i << endl;
            if(mp.find(pat[i]) == mp.end()) mp[pat[i]] = word[i];
            else if(mp[pat[i]] != word[i]) {
                // for(auto j: mp) cout << j.first << "-" << j.second << ", ";
                // cout << endl;
                return false;   
            }

            if(mp1.find(word[i]) == mp1.end()) mp1[word[i]] = pat[i];
            else if(mp1[word[i]] != pat[i]) {
                // for(auto j: mp1) cout << j.first << "-" << j.second << ", ";
                // cout << endl;
                return false; 
            }
        }

        return true;

        // unordered_map<char, int> a;
        // unordered_map<string, int> b;
        // if(pat.size() != word.size()) return false;

        // for(int i=0; i<pat.size(); i++){
        //     a[pat[i]]++;
        //     b[word[i]]++;
        //     if(a[pat[i]] != b[word[i]]) {
        //         for(auto j: a) cout << j.first << "-" << j.second << ",";
        //         cout << endl;
        //         for(auto j: b) cout << j.first << "-" << j.second << ",";
        //         cout << endl;

        //         cout << i << endl;
        //         return false;
        //     }
        // }

        // return true;
    }
};