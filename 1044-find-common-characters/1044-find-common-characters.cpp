class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> mp;
        for(auto i: words[0]) mp[i]++;
        words.erase(words.begin());
        // for(auto j: mp) cout << j.first << " " << j.second << ",  ";
        // cout << "-----------" << endl;
        for(auto i: words){
            unordered_map<char, int> temp;
            for(auto j: i) temp[j]++;
            for (auto& entry : mp) {
                entry.second = min(entry.second, temp[entry.first]);
            }
            
            // for(auto j: temp) {
            //     cout << j.first << "-" << j.second << endl;
            //     if(mp[j.first] == 0) continue;
            //     else {
            //         mp[j.first] = min(mp[j.first], j.second);
            //         cout << "update" << endl;
            //     }
            //     for(auto k: mp) {
            //         cout << k.first << "--" << k.second << endl;
            //         if(temp[k.first] != 0) {
            //             continue;
            //         }else{
            //             mp[k.first] = 0;
            //             cout << "change " << k.first << endl;
            //         }
            //     }
            // }
            // for(auto j: mp) cout << j.first << " " << j.second << ",  ";
            // cout << "-----------" << endl;
        }
        vector<string> ans;
        for(auto i: mp) if(i.second!=0) {
            int temp = i.second;
            while(temp--) ans.push_back(string(1,i.first));
        }
        return ans;
        // unordered_map<pair<char, int>, int> mp;
        // for(auto i: words){
        //     unordered_map<char, int> temp;
        //     for(auto j: i) {
        //         temp[j]++;
        //         mp[{j, temp[j]}]++;
        //     }
        // }
        // for(auto i: mp) if(i.second == 3) count++;
        // return count;
    }
};