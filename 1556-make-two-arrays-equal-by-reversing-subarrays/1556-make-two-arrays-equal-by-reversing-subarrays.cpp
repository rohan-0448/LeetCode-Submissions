class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        sort(target.begin(), target.end());

        return arr == target;
        // unordered_map<int, int> mp;
        // for(int i=0; i<target.size(); i++){
        //     mp[target[i]]++;
        //     mp[arr[i]]--;
        // }

        // for(auto i: mp) if(i.second != 0) return false;
        // return true;
    }
};