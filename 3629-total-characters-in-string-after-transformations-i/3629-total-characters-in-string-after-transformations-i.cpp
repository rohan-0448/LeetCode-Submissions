class Solution {
public:
    int MOD = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> mp(26,0);
        for(auto i: s) mp[i-'a']++;

        for(int i=0; i<t; i++){
            // unordered_map<char, int> temp;
            vector<int> temp(26,0);
            for(int d=0; d<25; d++){
                temp[d+1] = mp[d]%MOD;
                // if(mp[d]==25){
                //     temp[0]++;
                //     temp[1]++;
                // }
                // else temp[mp[d]+1]++;
            }
            temp[0] += mp[25]%MOD;
            temp[1] += mp[25]%MOD;

            for(int in=0; in<26; in++) mp[in] = temp[in]%MOD;
        }

        int cnt = 0;
        for(auto i: mp) cnt = (cnt+i)%MOD;
        return cnt;
    }
};