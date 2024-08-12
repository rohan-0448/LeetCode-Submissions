class Solution {
public:
    string binary_convert(int val, int n){
        string ans = "";
        while(n--){
            ans = to_string(val % 2) + ans;
            val /= 2;
        }
        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        set<int>st;
        for(auto i: nums) st.insert(stoi(i, 0, 2));
        for(int i=0; i<18; i++){
            if(st.find(i) == st.end()){
                ans = binary_convert(i, nums.size());
                break;
            }
        }
        return ans;
    }
};