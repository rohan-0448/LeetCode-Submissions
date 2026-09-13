class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> A, B;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(img1[i][j] == 1) A.push_back({i, j});
                if(img2[i][j] == 1) B.push_back({i, j});
            }
        }

        int best = 0;
        vector<vector<int>> cnt(n*2, vector<int> (n*2, 0));
        for(auto &a: A) {
            for(auto &b: B) {
                int x_change = b.first - a.first + n;
                int y_change = b.second - a.second + n;

                cnt[x_change][y_change]++;
                best = max(best, cnt[x_change][y_change]);
            }
        }

        return best;
    }
};