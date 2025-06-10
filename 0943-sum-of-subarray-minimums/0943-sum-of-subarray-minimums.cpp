class Solution {
public:
    // long long count(vector<int> arr, int n) {
    //     if(n == 0) return 0;
    //     if(n == 1) return arr[0];

    //     int ind = min_element(arr.begin(), arr.end()) - arr.begin();
    //     long long ans = 1LL * (ind+1) * (n-ind) * arr[ind];

    //     vector<int> left (arr.begin(), arr.begin()+ind);
    //     vector<int> right (arr.begin()+ind+1, arr.end());

    //     return ans + count(left, ind) + count(right, n-ind-1);
    // }

    long long count(vector<int>& arr, int l, int r) {
        if(l > r) return 0;
        if(l == r) return arr[l];

        int minIndex = l;
        for(int i=l; i<=r; i++) if(arr[i] < arr[minIndex]) minIndex = i;

        long long contrib = 1LL * (minIndex-l+1) * (r-minIndex+1) * arr[minIndex];
        return contrib + count(arr, l, minIndex-1) + count(arr, minIndex+1, r);
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), MOD = 1e9+7;
        long long ans = count(arr, 0, n-1);
        ans %= MOD;
        
        return (int) ans;
    }
};