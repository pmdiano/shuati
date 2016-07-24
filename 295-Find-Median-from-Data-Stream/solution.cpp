class MedianFinder {
    priority_queue<int, vector<int>, less<int>> left_max_heap;
    priority_queue<int, vector<int>, greater<int>> right_min_heap;
    int left_size, right_size;
public:
    MedianFinder(): left_size(0), right_size(0) {}

    // Adds a number into the data structure.
    void addNum(int num) {
        if (left_size == right_size) {
            if (right_size == 0 || num <= right_min_heap.top()) {
                left_max_heap.push(num);
            } else {
                left_max_heap.push(right_min_heap.top());
                right_min_heap.pop();
                right_min_heap.push(num);
            }
            left_size++;
        } else {
            if (num >= left_max_heap.top()) {
                right_min_heap.push(num);
            } else {
                right_min_heap.push(left_max_heap.top());
                left_max_heap.pop();
                left_max_heap.push(num);
            }
            right_size++;
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (left_size > right_size) {
            return left_max_heap.top();
        } else {
            return double(left_max_heap.top() + right_min_heap.top()) / 2.;
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();