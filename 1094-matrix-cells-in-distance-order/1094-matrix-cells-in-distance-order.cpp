class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int i, j, dis = 0;
        multimap<int, vector<int>> mp;
        for (i = 0; i < rows; i++) 
        {
            for (j = 0; j < cols; j++) 
            {
                vector<int> temp;
                dis = abs(i - rCenter) + abs(j - cCenter);
                temp.push_back(i);
                temp.push_back(j);
                mp.insert(pair<int, vector<int>>(dis, temp));
            }
        }

        // converting multimap into a 2d vector
        vector<vector<int>> ans;
        for (auto x: mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};