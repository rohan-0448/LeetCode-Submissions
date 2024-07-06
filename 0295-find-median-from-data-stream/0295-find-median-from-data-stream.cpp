class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lower.empty()) {
            // If lower heap is empty, push the number directly to it
            lower.push(num);
            return;
        }
        
        if (lower.size() > higher.size()) {
            if (lower.top() > num) {
                // If lower heap size is greater than higher heap size and the number is less than the
                // top element of the lower heap, push it to the higher heap after swapping the top
                // element of the lower heap with the number
                higher.push(lower.top());
                lower.pop();
                lower.push(num);
            } else {
                // If the number is greater than or equal to the top element of the lower heap,
                // push it directly to the higher heap
                higher.push(num);
            }
        } else {
            if (num > higher.top()) {
                // If higher heap size is greater than or equal to lower heap size and the number is
                // greater than the top element of the higher heap, push it to the lower heap after
                // swapping the top element of the higher heap with the number
                lower.push(higher.top());
                higher.pop();
                higher.push(num);
            } else {
                // If the number is less than or equal to the top element of the higher heap,
                // push it directly to the lower heap
                lower.push(num);
            }
        }
    }
    
    double findMedian() {
        double result = 0.0;
        
        if (lower.size() == higher.size()) {
            // If both heaps are of equal size, return the average of their top elements
            result = lower.top() + (higher.top() - lower.top()) / 2.0;
        } else {
            // If lower heap size is greater than higher heap size, return the top element of the lower heap
            // Otherwise, return the top element of the higher heap
            result = (lower.size() > higher.size()) ? lower.top() : higher.top();
        }
        
        return result;
    }
private:
    priority_queue<int> lower;  // Max heap
    priority_queue<int, vector<int>, greater<int>> higher;  // Min heap
};