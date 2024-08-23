class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg, f;
        for(auto i: nums){
            if(i>=0) pos.push_back(i);
            else neg.push_back(i);
        }
        int i = 0;
        while(i<pos.size()){
            f.push_back(pos[i]);
            f.push_back(neg[i++]);
        }
        return f;
    }
};