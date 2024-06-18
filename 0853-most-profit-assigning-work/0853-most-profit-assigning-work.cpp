class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxdif = *max_element(difficulty.begin(), difficulty.end());
        vector<int> vec(maxdif+1, 0);
        for (int i=0; i<difficulty.size(); i++) vec[difficulty[i]] = max(vec[difficulty[i]], profit[i]);
        for (int i=1; i<=maxdif; i++) vec[i] = max(vec[i], vec[i-1]);

        int ans = 0;
        for(auto i: worker) {
            if(i > maxdif) ans += vec[maxdif];
            else ans += vec[i];
        }
        return ans;
        // unordered_map<int, int> mp;
        // vector<pair<int, int>> vec;
        // for(int i=0; i<profit.size(); i++) vec.push_back({difficulty[i], profit[i]});
        // sort(vec.begin(), vec.end());
        // int max_profit = 0, ans = 0;
        // for(int i=0; i<vec.size(); i++){
        //     max_profit = max(max_profit, vec[i].second);
        //     mp[vec[i].first] = max_profit;
        // }
        // for(auto i: worker){
        //     while(i > 0){
        //         if(mp.find(i) != mp.end()) {
        //             ans += mp[i];
        //             cout << mp[i] << "-";
        //             break;
        //         }
        //         else i--;
        //         for(auto k: mp) cout << k.first << "-" << k.second << ", ";
        //         cout << endl;
        //     }
        // }
        // return ans;
    }
};