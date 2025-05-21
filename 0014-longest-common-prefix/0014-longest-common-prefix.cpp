class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int sm = INT_MAX, flag = 0;
        for(auto i: strs) if(sm > i.length()) sm = i.length();

        for(int i=1; i<=sm; i++){
            string temp = strs[0].substr(0, i);
            for(auto it: strs){
                if(temp != it.substr(0, i)){
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
            ans = temp;
        }
        return ans;
        // if(strs.size() == 0) return "";
        // int len = INT_MAX;
        // string mn = "";

        // for(auto i: strs) {
        //     if(i.length() < len){
        //         len = i.length();
        //         mn = i;
        //     }
        // }

        // if(mn == "") return "";

        // int index = 0;
        // while(true){
        //     for(int i=0; i<strs.size()-1; i++){
        //         if(strs[i][index] != strs[i+1][index]) return mn.substr(0, index);
        //     }
        //     index++;
        //     if(index == len) break;
        // }

        // return mn;
    }
};