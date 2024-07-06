class Solution {
public:
    int passThePillow(int n, int time) {
        if(n > time) return time+1;
        if((time/(n-1)) % 2 == 1){
            return n-(time%(n-1));
        }
        else{
            return time%(n-1) + 1;
        }
        return -1;
    }
};