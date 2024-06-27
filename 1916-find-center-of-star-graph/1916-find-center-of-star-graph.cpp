class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0], b = edges[0][1];
        for(auto i: edges){
            if(i[0]!=a && i[1]!=a) return b;
            else if(i[0]!=b && i[1]!=b) return a; 
        }
        return -1;
    }
};