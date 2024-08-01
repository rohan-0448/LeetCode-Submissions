class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto i: details) if(i.substr(11,2) > "60") count++;
        return count;   
    }
};