class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return 1;
        int sum = (n*(n+1))/2, sum2 = 0;
        for(int i=1; i<=n; i++){
            sum2+=i;
            if(sum==sum2) return i;
            sum-=i;
        }
        return -1;
        // for(int i=1; i<n; i++){
        //     sum1+=i;
        //     sum2+=n-i+1;
        //     prefix.push_back(sum1);
        //     postfix.push_back(sum2);
        // }
        // for(auto i: prefix) cout << i << " ";
        // cout << endl;
        // for(auto i: postfix) cout << i << " ";
        // cout << endl;
        // for(int i=prefix.size()-1; i>=0; i--) if(find(postfix.begin(), postfix.end(), prefix[i]) != postfix.end()) return i+1;
        // return -1;
    }
};