class Solution {
public:
    int romanToInt(string s) {
        /*
        reverse(s.begin(), s.end());
        map<string, int> mp1;
        mp1.push({"I", 1)};
        mp1.push({"V", 5)};
        mp1.push({"X", 10)};
        mp1.push({"L", 50)};
        mp1.push({"C", 100)};
        mp1.push({"D", 500)};
        mp1.push({"M", 1000)};
        int index = 0, val = 0;
        while(index<s.length()-1){
            if (mp1[s[index]] <= mp1[s[index+1]]) while(mp1[s[index]] <= mp1[s[index+1]]) val+=mp1[s[index++]];
            else {
                val+=mp1[s[index++]];
                val-=mp1[s[index--]];
            }
        }
        return val;
        */
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        map<char, int> m;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int val = 0;

        for(int i=0 ; i<s.length() ; i++){
            if(m[s[i]] < m[s[i+1]]) val -= m[s[i]];
            else val += m[s[i]];
        }

        return val;
    }
};