class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // vector<int> cost;
        // for(int i=0; i<s.length(); i++) cost.push_back(abs(s[i] - t[i]));
        // for(auto i: cost) cout << i << " ";

        int left=0, right=0, max_len = 0, curr_cost = 0;
        while(left<=right && right<s.length()){
            if(curr_cost<=maxCost) {
                max_len = max(max_len, right-left);
                curr_cost += abs(s[right]-t[right++]);
            }
            else while(left<s.length() && curr_cost>maxCost) curr_cost-=abs(s[left]-t[left++]);
        }
        if(right==s.length() && curr_cost<=maxCost) return max(max_len, right-left);
        return max_len;
    }
};