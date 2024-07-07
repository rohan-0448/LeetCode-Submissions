class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int len = INT_MAX;
        string mn = "";

        for(auto i: strs) {
            if(i.length() < len){
                len = i.length();
                mn = i;
            }
        }

        if(mn == "") return "";

        int index = 0;
        while(true){
            for(int i=0; i<strs.size()-1; i++){
                if(strs[i][index] != strs[i+1][index]) return mn.substr(0, index);
            }
            index++;
            if(index == len) break;
        }

        return mn;
    }
};