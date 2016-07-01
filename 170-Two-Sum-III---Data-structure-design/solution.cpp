class TwoSum {
    unordered_multiset<int> mySet;
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    mySet.insert(number);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (int i : mySet) {
	        if (2*i == value) {
	            if (mySet.count(i) >= 2) {
	                return true;
	            }
	        } else {
	            if (mySet.count(value-i) >= 1) {
	                return true;
	            }
	        }
	    }

	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);