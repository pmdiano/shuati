class ZigzagIterator {
    vector<vector<int>::const_iterator> its;
    vector<vector<int>::const_iterator> ends;
    int k;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2):
        its({v1.begin(), v2.begin()}),
        ends({v1.end(), v2.end()}),
        k(0) {
    }

    int next() {
        if (its[k] == ends[k]) k ^= 1;
        int ret = *its[k]++;
        k ^= 1;
        return ret;
    }

    bool hasNext() {
        return its[0] != ends[0] || its[1] != ends[1];
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */