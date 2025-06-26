class Solution {
public:
    bool check(vector<int> &piles, int h, int n) {
        long long cnt = 0;
        for(auto i: piles) {
            if(i%n==0) cnt += (i/n);
            else cnt += (i/n)+1;
        }

        cout << n << "-" << cnt << endl;
        
        return cnt<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());

        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(check(piles, h, mid)) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};