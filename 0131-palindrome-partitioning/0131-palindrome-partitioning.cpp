class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        func(0, s, temp, ans);
        return ans;
    }
    
    void func(int index, string s, vector<string> temp, vector<vector<string>> &ans){
        if(index == s.length()){
            ans.push_back(temp);
            return;
        }
        for(int i=index; i<s.length(); i++){
            if(ispalin(s, index, i+1)){
                temp.push_back(s.substr(index, i+1-index));
                func(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    
    bool ispalin(string s, int start, int end){
        string new1 = s.substr(start, end-start);
        string new2 = new1;
        reverse(new2.begin(), new2.end());
        return (new1 == new2);
    }
};