class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        set<int> s; 
        for(auto i: nums){
            s.insert(i);
        }
        vector<int> v;
        for(auto i: s){
            v.push_back(i);
        }
        sort(v.begin(), v.end());
        // for(auto i: v) cout << i << " ";
        cout << endl;
        int left = 0, right = 1, mx = 0;
        while(right<v.size()){
            if(v[right] == v[right-1]+1) right++;
            else {
                mx = max(mx, right-left);
                left = right;
                right++;
            }
        }
        mx = max(mx, right-left);
        return mx;
    }
};