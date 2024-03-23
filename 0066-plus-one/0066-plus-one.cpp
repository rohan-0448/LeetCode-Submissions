class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i=digits.size()-1; i>-1; i--){
            digits[i] += carry;
            if(digits[i] == 10){
                digits[i] = 0;
                carry = 1;
            }else{
                break;
            }
        }
        if(digits[0] == 0) digits.insert(digits.begin(), 1);
        return digits;
        
                // long long int sum=0, in=0;
        // for(int i=digits.size()-1; i>-1; i--){
        //     sum+=digits[i]*pow(10,in++);
        // }
        // sum++;
        // cout << sum-1 << endl;
        // vector<int> ans;
        // while(sum > 0){
        //     ans.push_back(sum%10);
        //     sum/=10;
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;
    }
};