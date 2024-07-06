class Solution {
public:
    bool isHappy(int n) {
        int c = 0;
        while(n != 1 && n != 10 && n != 13 && n != 68){
            int sum = 0;
            while(n != 0){
                sum += (n%10)*(n%10);
                n /= 10;
            }
            cout << sum << endl;
            n = sum;
            c++;
            if(c > 10) return false;
        }
        return true;
    }
};