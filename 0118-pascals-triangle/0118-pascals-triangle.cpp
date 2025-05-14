class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1}, {1,1}};

        vector<vector<int>> vec;
        vec.push_back({1});
        vec.push_back({1,1});
        
        for(int i=2; i<numRows; i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=1; j<i; j++) temp.push_back(vec[i-1][j]+vec[i-1][j-1]);
            temp.push_back(1);

            vec.push_back(temp);
        }

        return vec;
    }
};