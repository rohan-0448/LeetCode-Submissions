class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        
        int s=0,e=0;
        string str="";
        vector<string> ans;
        while(e<nums.size()-1){
            if(nums[e]+1==nums[e+1]) e++;
            else{
                if(s!=e) str=to_string(nums[s])+"->"+to_string(nums[e]);
                else str=to_string(nums[e]);
                ans.push_back(str);
                s=e+1;
                e=s;
            }
        }
        if(s!=e) str=to_string(nums[s])+"->"+to_string(nums[e]);
        else str=to_string(nums[e]);
        
        ans.push_back(str);
        return ans;
    }
};