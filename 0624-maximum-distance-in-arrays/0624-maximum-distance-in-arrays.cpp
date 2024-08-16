class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int, int>> mx_heap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mn_heap;

        for(int i=0; i<arrays.size(); i++){
            mx_heap.push({arrays[i].back(), i});
            mn_heap.push({arrays[i][0], i});
        }

        if(mx_heap.top().second != mn_heap.top().second) {
            // cout <<  mx_heap.top().first << " - " << mn_heap.top().first << endl;
            return mx_heap.top().first - mn_heap.top().first;
        }
        else{
            int mx1 = mx_heap.top().first;
            mx_heap.pop();
            int mx2 = mx_heap.top().first;

            int mn1 = mn_heap.top().first;
            mn_heap.pop();
            int mn2 = mn_heap.top().first;

            // cout << mx1 << ", " << mx2 << " --- " << mn1 << ", " << mn2 << endl;

            return max(mx1-mn2, mx2-mn1);
        }

        return -1;
        
        // int mx = INT_MIN;
        // for(int i=0; i<arrays.size(); i++){
        //     for(int j=0; j<arrays.size(); j++){
        //         if(i!=j){
        //             mx = max(mx, arrays[j].back()-arrays[i][0]);
        //         }
        //     }
        // }
        // return mx;
    }
};