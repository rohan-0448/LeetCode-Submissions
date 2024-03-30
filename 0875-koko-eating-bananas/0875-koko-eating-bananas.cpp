class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long left = 1, right = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX,  mid = 0;
        while(left<=right){
            mid = (right+left)/2;
            long long c = 0;
            for(auto i: piles){
                if(i%mid==0) c += (i/mid);
                else c+= ((i/mid)+1);
            }
            cout << c << " " << mid << endl;
            if(c > h) left = mid+1;
            else{
                ans = min(mid, ans);
                right = mid-1;
            }
        }
        return ans;
    }
};