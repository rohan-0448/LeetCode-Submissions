class Solution {
public:

    bool check(map<char, int> a, map<char, int> b){
        vector<pair<char, int>> a1, b1;
        for(auto i: a) if(i.second != 0) a1.push_back(i);
        for(auto i: b) if(i.second != 0) b1.push_back(i);

        return a1 == b1;
    }

    bool checkInclusion(string s1, string s2) {
        
        int n1 = s1.length(), n2 = s2.length();
        map<char, int> mp1, mp2;

        if(n1 > n2) return false;

        for(int i=0; i<n1; i++) {
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }

        if(check(mp1, mp2)) return true;

        for(int i=0, j=n1; j<n2; i++, j++){
            if(mp1[s2[j]] < 0) continue;
            mp2[s2[i]]--;
            mp2[s2[j]]++;
            
            if(check(mp1, mp2)) return true;
        }

        return false;
    }
};