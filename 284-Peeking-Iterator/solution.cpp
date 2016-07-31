// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    bool cached;
    int cached_num;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums), cached(false) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!cached) {
            cached_num = Iterator::next();
            cached = true;
        }
        return cached_num;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (cached) {
	        cached = false;
	        return cached_num;
	    } else {
	        return Iterator::next();
	    }
	}

	bool hasNext() const {
	    return cached || Iterator::hasNext();
	}
};