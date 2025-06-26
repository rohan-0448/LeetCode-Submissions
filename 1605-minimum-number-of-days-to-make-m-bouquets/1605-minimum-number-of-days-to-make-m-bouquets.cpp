class Solution {
public:
    bool check(vector<int>& days, int bq_cnt, int flowers, int day) {
        int curr = 0, cnt = 0;
        for(int i=0; i<days.size(); i++) {
            if(days[i] <= day) curr++;
            else curr = 0;

            if(curr == flowers) {
                cnt++;
                curr = 0;
            }
        }
        return cnt >= bq_cnt;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        
        int ans = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;

            if(check(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};