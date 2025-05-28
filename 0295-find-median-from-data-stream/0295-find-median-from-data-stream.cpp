class MedianFinder {
public:
    priority_queue<int> mx_heap; // max at top -- left
    priority_queue<int, vector<int>, greater<int>> mn_heap; // min at top -- right
    // vector<int> nums;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx_heap.size() == 0 || mx_heap.top() < num) mn_heap.push(num);
        else mx_heap.push(num);

        if(mn_heap.size() > mx_heap.size()) {
            int temp = mn_heap.top();
            mn_heap.pop();
            mx_heap.push(temp);
        }
        if(mx_heap.size() > mn_heap.size()+1) {
            int temp = mx_heap.top();
            mx_heap.pop();
            mn_heap.push(temp);
        }
        // auto it = lower_bound(nums.begin(), nums.end(), num);
        // nums.insert(it, num);
    }
    
    double findMedian() {
        int mx = mx_heap.top(), mn = mn_heap.top();
        if(mx_heap.size() > mn_heap.size()) return mx;
        else return (float)(mx + mn) / 2.0;
        // else return mx+mn;

        // int n = nums.size();
        // if(n%2==1) return nums[n/2];
        // else return (nums[n/2] + nums[(n-1)/2]) / 2.0;
    }
};