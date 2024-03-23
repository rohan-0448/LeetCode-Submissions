class Solution {
public:
    bool isPalindrome(int x) {
        // if(x<0) return false;
        // int num=0, cpy= x;
        // // int len = to_string(cpy).length;
        // while(cpy!=0){
        //     num+=cpy%10;
        //     num*=10;
        //     cpy/=10;
        // }
        // // cout << num << endl;
        // return x==num/10;
        string str1 = to_string(x);
        string reversed = str1;
        reverse(reversed.begin(), reversed.end());
        return str1 == reversed;
    }
};