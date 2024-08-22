//C++ Code
class Solution {
public:
    int bitwiseComplement(int num) {
        int m = num, temp = 0;
        if(num == 0) return 1;
        
        while(m != 0){
            temp=(temp << 1)|1;
            m=m>>1;
        }
        return (~num) & temp;
    }
};