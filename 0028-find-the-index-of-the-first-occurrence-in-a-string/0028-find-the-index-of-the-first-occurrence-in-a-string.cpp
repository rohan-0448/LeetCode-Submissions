class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        for(int i=0; i<haystack.size(); i++){
            if(haystack[i]==needle[0]){
                int index = 1;
                ans = i;
                while(index<needle.size()){
                    if(haystack[i+index]!=needle[index]){
                        ans=-1;
                        break;
                    }
                    index++;
                }
            }
            if(ans!=-1) return ans;
        }
        return -1;
    }
};