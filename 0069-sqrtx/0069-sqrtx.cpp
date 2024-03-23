class Solution {
public:
    int mySqrt(int x) {
        /*
        int l = 0, r = (x+1)/2;
        int mid=0;

        while(1){
            mid = (l+r)/2;

            if(mid*mid < x) l = mid;
            else if(mid*mid > x) r = mid;
            else break;

        }*/
        
        // return pow(x, 0.5);
        return (floor (sqrt(x)));
    }
};