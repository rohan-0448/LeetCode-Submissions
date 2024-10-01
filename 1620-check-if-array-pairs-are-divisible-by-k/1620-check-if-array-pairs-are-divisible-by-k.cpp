class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for(int i: arr) {
            int rem = i%k;
            if(rem<0) rem += k;
            freq[rem]++;
        }
        
        if(freq[0]%2 != 0) return false;
        for(int i=1; i<=k/2; i++) if(freq[i] != freq[k-i]) return false;
        
        return true;
    }
};