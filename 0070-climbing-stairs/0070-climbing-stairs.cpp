class Solution {
public:

    int check(int n, int index){
        if(index <= 1) return 1;
        
        int left = check(n, index-1);
        int left2 = check(n, index-2);

        return left + left2;
    }

    int climbStairs(int n) {
        // return check(n, n);
        int a = 0, b = 1, curr = 0;
        while(n--){
            curr = a + b;
            a = b;
            b = curr;
        }
        return b;
    }
};