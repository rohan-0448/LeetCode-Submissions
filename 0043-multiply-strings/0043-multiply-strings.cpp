class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n1 = num1.length(), n2 = num2.length();
        vector<int> ans(n1+n2, 0);

        int index = 0;
        for(int i=n2-1; i>-1; i--){
            index = n2-i-1;
            for(int j=n1-1; j>-1; j--){
                int prod = (num2[i]-'0') * (num1[j]-'0');
                ans[index] += prod%10;
                if(ans[index]>=10) {
                    ans[index+1] += ans[index]/10;
                    ans[index] %= 10;
                }
                ans[index+1] += prod/10;
                index++;
            }
        }
        // ans.erase(ans.begin()+index, ans.end());
        // cout << index << endl;
        reverse(ans.begin(), ans.end());
        for(auto i: ans) cout << i << " ";
        cout << endl;

        string final_a = "";
        for(int i=0; i<ans.size(); i++) {
            if(i == 0 && ans[i]==0) while(ans[i] == 0) i++;
            final_a+=('0'+ans[i]);
        }

        return final_a;
    }
};