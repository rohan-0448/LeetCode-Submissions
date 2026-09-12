class Solution {
public:
    struct Node{
        long long score = -1;
        vector<int> idxs;
    };
    vector<vector<Node>> t;

    int binary_srch(vector<vector<int>> &intervals, int num) {
        int lo = 0, hi = intervals.size()-1, res = intervals.size();

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if(intervals[mid][0] > num) {
                hi = mid-1;
                res = mid;
            } else lo = mid+1;
        }

        return res;
    }

    Node solve(vector<vector<int>> &intervals, int index, int k, vector<int> &next_ind) {
        if(k == 0 || index >= intervals.size()) return Node();

        if(t[index][k].score != -1) return t[index][k];

        Node skip = solve(intervals, index+1, k, next_ind);

        int weight = intervals[index][2];
        int ind = intervals[index][3];

        Node temp = solve(intervals, next_ind[index], k-1, next_ind);
        
        Node take;
        take.score = temp.score + weight;
        take.idxs = temp.idxs;
        take.idxs.push_back(ind);

        sort(begin(take.idxs), end(take.idxs));

        Node result;
        
        if(skip.score > take.score) result = skip;
        else if(skip.score < take.score) result = take;
        else result = (skip.idxs < take.idxs)? skip: take;

        return t[index][k] = result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        for(int i=0; i<n; i++) intervals[i].push_back(i);
        sort(begin(intervals), end(intervals));

        vector<int> next_ind;
        for(int i=0; i<n; i++) {
            int c_end = intervals[i][1];
            next_ind.push_back(binary_srch(intervals, c_end));
        }

        t.assign(n+1, vector<Node>(5));
        return solve(intervals, 0, 4, next_ind).idxs;
    }
};