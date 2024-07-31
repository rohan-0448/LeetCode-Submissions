class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for(int i=1; i<=n; i++) {
            int width=0, height=0;
            for(int j=i; j>0; j--) {
                width += books[j-1][0];
                if(width > shelfWidth) break;
                height = max(height, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1]+height);
            }
        }
        return dp[n];
    }
};

// class Solution {
// public:
//     void check(vector<vector<int>>& books, int& width, int index, int curr, int& mn, vector<pair<int, int>> vec, int shelf){
//         if(curr >= mn) return;
//         if(index == books.size()){
//             mn = min(mn, curr + vec[shelf].second);
//             return;
//         }
        
//         if(width-vec[shelf].first >= books[index][0]) {
//             int prev = vec[shelf].second;
//             vec[shelf].second = max(vec[shelf].second, books[index][1]);
//             vec[shelf].first += books[index][0];
//             check(books, width, index+1, curr, mn, vec, shelf);
//             vec[shelf].first -= books[index][0];
//             vec[shelf].second = prev;
//         }

//         vec[shelf+1] = {books[index][0], books[index][1]};
//         check(books, width, index+1, curr + vec[shelf].second, mn, vec, shelf+1);
//     }

//     int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
//         vector<pair<int, int>> vec(books.size()+1, {0,0});
//         int mn = INT_MAX;
//         check(books, shelfWidth, 0, 0, mn, vec, 0);

//         return mn;
//     }
// };