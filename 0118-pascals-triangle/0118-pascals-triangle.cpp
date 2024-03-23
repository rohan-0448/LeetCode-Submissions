class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> vec;
        vec.push_back({1});
        if(n == 1) return vec;
        vec.push_back({1,1});
        if(n==2) return vec;
        for(int i=3; i<=n; i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=1; j<=i-2; j++){
                temp.push_back(vec[vec.size()-1][j] + vec[vec.size()-1][j-1]);
            }
            temp.push_back(1);
            vec.push_back(temp);
        }
        return vec;
    }
};