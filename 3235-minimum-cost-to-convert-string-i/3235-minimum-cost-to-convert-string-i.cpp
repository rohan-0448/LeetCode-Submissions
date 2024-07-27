class Solution {
public:

    void floydwashell(vector<vector<long long>> &adj, vector<char>& org, vector<char> &change, vector<int>&cost){
        for(int i=0; i<org.size(); i++) adj[org[i]-'a'][change[i]-'a'] = min(adj[org[i]-'a'][change[i]-'a'], (long long)cost[i]);
        
        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    adj[i][j] = min(adj[i][j], (long long)adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adj(26, vector<long long>(26, INT_MAX));

        floydwashell(adj, original, changed, cost);

        long long sum = 0;
        for(int i=0; i<source.length(); i++){
            if(source[i] == target[i]) continue;

            if(adj[source[i]-'a'][target[i]-'a'] == INT_MAX) return -1;

            sum += adj[source[i]-'a'][target[i]-'a'];
        }

        return sum;
    //     unordered_map<char, vector<pair<char, int>>> mp;
    //     for (int i=0; i<original.size(); i++) mp[original[i]].push_back({changed[i], cost[i]});

    //     long long sum = 0;
    //     for (int i=0; i<source.length(); i++) {
    //         if(source[i] == target[i]) continue;
            
    //         bool found = false;
    //         int min_cost = INT_MAX;
    //         if(mp.find(source[i]) != mp.end()) {
    //             for(auto& p: mp[source[i]]) {
    //                 if(p.first == target[i]) {
    //                     found = true;
    //                     min_cost = min(min_cost, p.second);
    //                 }
    //             }
    //         }

    //         if (!found) return -1;
    //         sum += min_cost;
    //     }

    //     return sum;
    }
};
