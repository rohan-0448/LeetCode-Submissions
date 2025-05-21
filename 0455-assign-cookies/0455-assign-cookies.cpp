class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, n = g.size(), m = s.size();

        while(i<n && j<m){
            if(g[i] <= s[j]) {
                i++;
                j++;
            }
            else j++;
        }
        return i;

        // int index = n-1, size = m-1;
        // while(index>=0){
        //     int curr = s[size--];
        //     while(index >= 0 && g[index] < curr) index--;
        //     if(index == -1) break;
        //     cnt++;
        //     index--;
        // }
        // return cnt;
    }
};