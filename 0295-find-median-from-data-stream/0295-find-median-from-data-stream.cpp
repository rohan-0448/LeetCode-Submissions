class MedianFinder {
public:
    vector<int> nums;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto it = lower_bound(nums.begin(), nums.end(), num);
        nums.insert(it, num);
    }
    
    double findMedian() {
        int n = nums.size();
        if(n%2==1) return nums[n/2];
        else return (nums[n/2] + nums[(n-1)/2]) / 2.0;
    }
};