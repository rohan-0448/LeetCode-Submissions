class MedianFinder {
public:
    vector<int> nums;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto it = lower_bound(nums.begin(), nums.end(), num);
        nums.insert(it, num);
        for(auto i: nums) cout << i << " ";
        cout << endl;
        // if(nums.empty()) nums.push_back(num);
        // else{
        //     int left = 0, right = nums.size()-1;
        //     while(left < right){
        //         int mid = left + right/2;

        //         if(nums[mid] > num) right = mid;
        //         else left = mid;
        //     }
        //     nums.insert(nums.begin()+left, num);
        // }
    }
    
    double findMedian() {
        int n = nums.size();
        if(n%2==1) return nums[n/2];
        else return (nums[n/2] + nums[(n-1)/2]) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */