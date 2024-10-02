class Solution {
public:
    vector<int> arrayRankTransform(std::vector<int>& arr) {
        unordered_map<int, int> rank;
        vector<int> temp = arr; 
        
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        
        for(int i=1; i<=temp.size(); i++) rank[temp[i-1]] = i;
        for(int i=0; i<arr.size(); i++) arr[i] = rank[arr[i]];

        return arr;
    }
};