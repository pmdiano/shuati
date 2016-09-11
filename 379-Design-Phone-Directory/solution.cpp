class PhoneDirectory {
    int N, next;
    vector<int> used;
    vector<int> recycle;

public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers)
        : N(maxNumbers)
        , next(0)
        , used(maxNumbers, 0) {
        recycle.reserve(N);
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (next == N && recycle.empty()) {
            return -1;
        }

        if (!recycle.empty()) {
            int num = recycle.back();
            recycle.pop_back();
            used[num] = 1;
            return num;
        }

        used[next] = 1;
        return next++;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return number >= 0 && number < N && !used[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (used[number]) {
            used[number] = 0;
            if (number == next-1) {
                next--;
            } else {
                recycle.push_back(number);
            }
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */