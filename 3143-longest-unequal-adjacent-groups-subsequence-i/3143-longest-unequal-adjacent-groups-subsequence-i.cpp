class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<int> ind(0), ind2(0);
        // int count = accumulate(groups.begin(), groups.end(), 0);
        int n = groups.size();
        if(n==1) return words;

        int i=0;    
        while(i<groups.size() && groups[i]!=1) i++;
        if(i!=groups.size()) ind.push_back(i);
        for(; i<n; i++){
            if(groups[ind.back()] != groups[i]) ind.push_back(i);
        }

        i=0;
        while(i<groups.size() && groups[i]!=0) i++;
        if(i!=groups.size()) ind2.push_back(i);
        for(; i<n; i++){ 
            if(groups[ind2.back()] != groups[i]) ind2.push_back(i);
            // if(groups[ind2.back()] == 1 && groups[i] == 0) ind2.push_back(i);
        }

        vector<string> ans;
        if(ind.size() > ind2.size()) for(auto i: ind) ans.push_back(words[i]);
        else for(auto i: ind2) ans.push_back(words[i]);

        return ans;
    }
};