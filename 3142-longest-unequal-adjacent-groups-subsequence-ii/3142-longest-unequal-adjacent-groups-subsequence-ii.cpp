class Solution {
public:

    int hamming(string &a, string &b){
        if(a.length() != b.length()) return 0;
        int c = 0;
        for(int i=0; i<a.length(); i++){
            if(a[i]!=b[i]) c++;
        }
        return c;
    }

    vector<string> check(vector<pair<string, int>> &curr){
        int n = curr.size();
        vector<pair<int, int>> dp(n, {0, 0});
        for(int i=0; i<n; i++) dp[i] = {1, -1};

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(hamming(curr[i].first, curr[j].first) == 1 && curr[i].second != curr[j].second){
                    if(dp[j].first < dp[i].first+1) dp[j] = {dp[i].first+1, i};
                }
            }
        }

        for(auto [x,y]: dp) cout << x << " " << y << ", ";
        cout << endl;

        vector<string> ans;
        int mx = INT_MIN, ind = -1;
        for(int i=0; i<dp.size(); i++) {
            if(dp[i].first > mx) {
                mx = dp[i].first;
                ind = i;
            }
        }
        if(ind == -1) return {};

        while(ind != -1){
            ans.push_back(curr[ind].first);
            ind = dp[ind].second;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // vector<string> best;
        // int mx = INT_MIN;

        // if(words.size() == 1) return words;

        // for(int len = 1; len <= 10; len++) {
        //     vector<pair<string, int>> curr;
        //     for(int i = 0; i < words.size(); i++) {
        //         if(words[i].length() == len)
        //             curr.push_back({words[i], groups[i]});
        //     }

        //     if(!curr.empty()) {
        //         vector<string> out = check(curr);
        //         if((int)out.size() > mx) {
        //             mx = out.size();
        //             best = out;
        //         }
        //     }
        // }

        // return best;

        
        vector<vector<string>> ans;
        int mx = INT_MIN;
        if(words.size()==1) return words;

        for(int i=1; i<11; i++){
            vector<pair<string, int>> curr;
            for(int it=0; it<words.size(); it++) if(words[it].length() == i) curr.push_back({words[it], groups[it]});
            // for(auto [x,y]: curr) cout << x << "-" << y << ", ";
            cout << endl;
            if(curr.size()!=0) {
                vector<string> out = check(curr);
                // for(auto x: out) cout << x << ", ";
                cout << endl;
                ans.push_back(out);
                int d = out.size();
                if(mx < d) mx = d;
            }
        }

        for(auto i: ans) if(i.size() == mx) return i;
        return {};
        
        
        
        
        // vector<vector<string>> ans;
        
        // int n = words.size(), mx = INT_MIN;

        // if(n==1) return words;

        // for(int i=0; i<n-1; i++){
        //     vector<pair<string, int>> temp;
        //     temp.push_back({words[i], groups[i]});
        //     int curr = i+1;
        //     while(curr<n){
        //         if(hamming(temp.back().first, words[curr]) == 1 && temp.back().second != groups[curr]) temp.push_back({words[curr], groups[curr]});
        //         curr++;
        //     }
        //     vector<string> fin;
        //     for(auto [x,y]: temp){
        //         fin.push_back(x);
        //     }
        //     int d = fin.size();
        //     mx=max(mx,d);
        //     ans.push_back(fin);
        //     for(auto [x, y]: temp) cout << x << "-" << y << endl;
        //     for(auto x: fin) cout << x << " ---- " << endl;
        // }
        // cout << mx << endl;
        // for(auto i: ans){
        //     for(auto j: i) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        //     if(i.size() == mx) return i;
        // }
        // return {};
    }
};