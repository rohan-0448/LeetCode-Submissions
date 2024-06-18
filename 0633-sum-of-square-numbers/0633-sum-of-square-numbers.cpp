class Solution {
public:

    bool issquare(int a){
        double b = sqrt(a);
        int c = b;
        if(b == c) return true;
        return false;
    }

    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        for(int i=1; i<=46340 && i*i<=c; i++){
            if( issquare(c - (i*i)) ) return true;
        }
        return false;
    }
};