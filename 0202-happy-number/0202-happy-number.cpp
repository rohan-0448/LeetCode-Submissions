class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        int total = 0;
        while(s.count(n) == 0) {
            if(n == 1) return true;
            s.insert(n);
            total = 0;
            while(n) {
                total += (n % 10) * (n % 10);
                n /= 10;
            }
            n = total;
        }
        return false;
    }
};