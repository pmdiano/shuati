class Vector2D {
    vector<vector<int>>::const_iterator row_it, row_end;
    vector<int>::const_iterator it;

    void skip_empty() {
        if (it != row_it->end())
            return;
        while (++row_it != row_end) {
            it = row_it->begin();
            if (it != row_it->end())
                break;
        }
    }

public:
    Vector2D(vector<vector<int>>& vec2d) {
        row_it = vec2d.begin();
        row_end = vec2d.end();
        if (row_it != row_end) {
            it = row_it->begin();
            skip_empty();
        }
    }

    int next() {
        int ret = *it;
        it++;
        skip_empty();
        return ret;
    }

    bool hasNext() {
        return row_it != row_end && it != row_it->end();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */