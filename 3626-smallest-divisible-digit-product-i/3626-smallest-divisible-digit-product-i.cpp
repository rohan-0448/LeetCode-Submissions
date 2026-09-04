class Solution {
public:
    int prod(int n) {
        int res = 1;
        while(n > 0) {
            res *= (n % 10);
            n /= 10;
        }
        return res;
    }

    int smallestNumber(int n, int t) {
        while(true) {
            if(prod(n) % t == 0) return n;
            n++;
        }
    }
};