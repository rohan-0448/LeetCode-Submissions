class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start ^ goal, cnt = 0;
        
        while(temp>0) {
            cnt += temp & 1; 
            temp >>= 1;
        }
        
        return cnt;
    }
};