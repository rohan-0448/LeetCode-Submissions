class Solution {
public:

    int check(int n, int index){
        if(index == n-1) return 0;
        if(index >= n) return 0;

        return check(n, index+1) + check(n, index+2);
    }

    int climbStairs(int n) {
        // return check(n, 0);
        int a = 0, b = 1, curr = 0;
        while(n--){
            curr = a + b;
            a = b;
            b = curr;
        }
        return b;
    }
};