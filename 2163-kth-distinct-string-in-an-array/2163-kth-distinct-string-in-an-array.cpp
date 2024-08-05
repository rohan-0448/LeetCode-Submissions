class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        // for(int i=0; i<arr.size(); i++){
        //     if(find(arr.begin()+i+1, arr.end(), arr[i]) == arr.end()) k--;
        //     if(!k) return arr[i];
        // }
        // return "";
        unordered_map<string, int> mp;
        for(auto i: arr) mp[i]++;

        // for(auto i: freq) cout << i.first << "-" << i.second << " ";
        // cout << endl;
        for(auto i: arr) {
            if(mp[i]==1){
                k--;
                if(k==0) return i;
            }
        }
        return "";
    }
};