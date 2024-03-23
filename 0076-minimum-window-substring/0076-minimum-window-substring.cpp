class Solution {
public:
string minWindow(string s, string t) {
        if (s == t) return t;
        if (t.length() > s.length()) return "";
        
        unordered_map<char, int> mp, np;
        for (auto i : t) {
            np[i]++;
        }
        
        int n = np.size(), left = 0, minLen = INT_MAX, minLeft = 0;
        bool ans = false;

        for (int right = 0; right < s.length(); right++) {
            if (np[s[right]] != 0) {
                mp[s[right]]++;
                if (mp[s[right]] == np[s[right]]) n--;

                while (n == 0) {
                    int currentLen = right - left + 1;
                    if (currentLen < minLen) {
                        minLen = currentLen;
                        minLeft = left;
                        ans = true;
                    }

                    if (np[s[left]] != 0) {
                        mp[s[left]]--;
                        if (mp[s[left]] < np[s[left]]) n++;
                    }

                    left++;
                }
            }
        }

        if (ans) {
            return s.substr(minLeft, minLen);
        } else {
            return "";
        }
    }
    // string minWindow(string s, string t) {
    //     if(s==t) return t;
    //     if(t.length() > s.length()) return "";
    //     unordered_map<char, int> mp, np;
    //     for(auto i: t){
    //         np[i]++;
    //     }
    //     int n=np.size(), left=0;
    //     string mn = s;
    //     bool ans = false;
    //     for(int right=0; right<s.length(); right++){
    //         if(np[s[right]]!=0){
    //             mp[s[right]]++;
    //             if(mp[s[right]]==np[s[right]]) n--;
    //             while(n==0){
    //                 // cout << left << " " << right << "--" << s.substr(left, right-left+1) << "-----" << mn << endl;
    //                 if(right-left+1 <= mn.length()){
    //                     mn = s.substr(left, right-left+1);
    //                     ans = true;
    //                 }
    //                 if(np[s[left]]!=0){
    //                     mp[s[left]]--;
    //                     if(mp[s[left]] < np[s[left]]) n++;
    //                 }
    //                 left++;
    //             }
    //         }
    //     }
    //     if(ans) return mn;
    //     else return "";
    //     // int n = t.length();
    //     // int m = s.length();
    //     // int left=0, right=0;
    //     // string mn = t;
    //     // bool ans = false;
    //     // while(right<m){
    //     //     if(n==t.length()) left = right;
    //     //     if(mp[s[right]]>0){
    //     //         mp[s[right]]--;
    //     //         n--;
    //     //         if(n==0){
    //     //             if(right-left < mn.length());
    //     //             cout << s.substr(left, right+1) << endl;
    //     //             ans = true;
    //     //             mn = s.substr(left, right+1);
    //     //             left = right-1;
    //     //             // right++;
    //     //             n = t.length();
    //     //             mp = np;
    //     //         }
    //     //     }
    //     //     right++;
    //     // }
    //     // if(!ans) return "";
    //     // return mn;
    // }
};