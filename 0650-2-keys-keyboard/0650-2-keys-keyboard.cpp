class Solution {
public:
    bool isprime(int n){
        if(n==1){
            return false;
        }
        if(n==2 || n==3){
            return true;
        }
        for(int i=1;i<n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;

    }
    int recur(int n){
        if(n==1){
            return 0;
        }
        if(isprime(n)){
            return n;
        }
        for(int i=2;i<n;i++){
            if(n%i==0){
                return (recur(i))+recur(n/i);
            }
        }
        return n;
    }
    int minSteps(int n) {
        return recur(n);
    }
};