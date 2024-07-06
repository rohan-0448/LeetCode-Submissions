class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i=0; i<=min(k, n-1); i++) {
            mp[nums[i]]++;
            if(mp[nums[i]]>1) return true;
        }
        // for(auto i: mp) cout << i.first << "-" << i.second << ", ";
        // cout << endl;
        for(int i=k+1; i<n; i++){
            mp[nums[i-k-1]]--;
            mp[nums[i]]++;

            if(mp[nums[i]]>1) return true;

            // for(auto b: mp) cout << b.first << "-" << b.second << ", ";
            // cout << endl;
        }

        return false;
    }
};