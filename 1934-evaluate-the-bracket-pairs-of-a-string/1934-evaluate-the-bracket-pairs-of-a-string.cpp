class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "", temp = "";
        int flag = 0;
        
        unordered_map<string, string> mp;
        for(auto &i: knowledge) mp[i[0]] = i[1];

        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                flag = 1;
                temp = "";
                continue;
            }
            
            if(s[i] == ')') {
                string val = "?";
                cout << temp << endl;
                if(mp.find(temp) != mp.end()) val = mp[temp];
                
                ans += val;
                flag = 0;
                continue;
            }

            if(flag == 0) ans += s[i];
            else temp += s[i];

            // cout << ans << endl;
       }

        return ans;
    }
};