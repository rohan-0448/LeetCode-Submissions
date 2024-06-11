class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> words;
        unordered_map<string, int> roots;
        for(auto i: dictionary) roots[i]++;
        int index = 0;
        for(int i=0; i<sentence.length(); i++){
            if(sentence[i] == ' ' || i == sentence.length()-1) {
                if(i == sentence.length()-1)words.push_back(sentence.substr(index, i-index+1));
                else words.push_back(sentence.substr(index, i-index));
                index = i+1;
            }
        }
        string ans = "";
        for(auto i: words) {
            int flag = 0;
            for(int j=0; j<i.length(); j++){
                if(roots[i.substr(0, j)] != 0) {
                    ans += i.substr(0, j);
                    flag = 1;
                    break;
                }
            }
            if(!flag) ans += i; 
            ans += " ";
        }

        return ans.substr(0, ans.length()-1);
    }
};