class Solution {
public:
    bool checkValidString(string s) {
        // Keep track of min and max left brackets
        int leftmin = 0, leftmax = 0;
        for(auto i: s) {
            if(i == '(') {
                leftmin++;
                leftmax++;
            }else if(i == ')') {
                if(leftmin>0) leftmin--;
                leftmax--;
            }else{
                if(leftmin>0) leftmin--;
                leftmax++;
            }

            if(leftmax < 0) return false;
        }
        return leftmin == 0;
    }
};