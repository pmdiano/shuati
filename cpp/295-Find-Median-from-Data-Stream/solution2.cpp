class MedianFinder {
    priority_queue<int, vector<int>, less<int>> small;
    priority_queue<int, vector<int>, greater<int>> large;
    bool even = true;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (even) {
            large.push(num);
            small.push(large.top());
            large.pop();
        } else {
            small.push(num);
            large.push(small.top());
            small.pop();
        }
        even = !even;
    }

    // Returns the median of current data stream
    double findMedian() {
        if (even) {
            return double(small.top() + large.top()) / 2.0;
        } else {
            return small.top();
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();