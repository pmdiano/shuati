class MovingAverage {
    const int _size;
    queue<int> _q;
    double _sum;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size): _size(size), _sum(0.) {
    }

    double next(int val) {
        _q.push(val);
        _sum += val;
        if (_q.size() > _size) {
            _sum -= _q.front();
            _q.pop();
        }
        return _sum / _q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */