class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0), leftSum = 0;
        for (int i=0; i<nums.size(); i++) {
            if(leftSum == (totalSum-leftSum-nums[i])) return i;
            leftSum += nums[i];
        }
        return -1;
    }
        // vector<int> prefix, postfix;
        // int sum1 = 0, sum2 = 0, n = nums.size();
        // prefix.push_back(sum1);
        // postfix.push_back(sum2);
        // for(int i=0; i<n; i++){
        //     sum1+=nums[i];
        //     prefix.push_back(sum1);
        //     sum2+=nums[n-i-1];
        //     postfix.push_back(sum2);
        // }
        // reverse(postfix.begin(),postfix.end());
        // for(auto i: prefix) cout << i << " ";
        // cout << endl; 
        // for(auto i: postfix) cout << i << " ";
        // cout << endl; 
        // if(postfix[1]==0) return 0;
        // for(int i=1; i<=n; i++) if(prefix[i-1] == postfix[i+1]) return i;
        // if(prefix[n-2]==0) return n-1;
        // return -1;
    // }
};