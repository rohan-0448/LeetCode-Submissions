class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;
        for(auto i: wordList) mp[i]++;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            string curr = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(curr == endWord) return dist;

            for(int i=0; i<curr.length(); i++){
                for(int j=1; j<26; j++){
                    string updated = "";
                    
                    updated += curr.substr(0, i);
                    updated += ( ( ( curr[i]-'a' ) + j ) % 26) + 'a';
                    updated += curr.substr(i+1);
                
                    if(mp[updated] != 0) {
                        q.push({updated, dist+1});
                        mp[updated] = 0;
                    }
                }
            }
        }
        return 0;
    }
};