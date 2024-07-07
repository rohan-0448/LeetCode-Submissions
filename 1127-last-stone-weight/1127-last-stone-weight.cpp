class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        multiset<int,greater<>>ms(v.begin(),v.end());
        while(ms.size()>=2){
            int n1=*ms.begin();
            ms.erase(ms.begin());
            int n2=*ms.begin();
            ms.erase(ms.begin());
            if(n1==n2) continue;
            else ms.insert(max(n1,n2)-min(n1,n2));
        }
        int ans=*ms.begin();
        return ans;
    }
};