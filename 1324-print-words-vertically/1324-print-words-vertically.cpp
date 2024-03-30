class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        int start = 0, len = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                words.push_back(s.substr(start, i-start));
                len = max(len, i-start);
                start = i+1;
            }
            if(i == s.length()-1){
                words.push_back(s.substr(start, i-start+1));
                len = max(len, i-start+1);
                break;
            }
        }
        for(auto i: words) cout << i << " ";
        vector<string> ans (len,"");
        for(int k=0; k<words.size(); k++){
            string i = words[k];
            cout << i << endl;
            for(int j=0; j<len; j++){
                if(j < i.length()) ans[j] += i[j];
                else ans[j] += ' ';
            }
        }
        for(auto& i: ans){
            while(i[i.size()-1] == ' ') i = i.substr(0,i.size()-1);
        }
        return ans;
    }
};