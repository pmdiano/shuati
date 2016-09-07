class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k <= 1) return str;
        int count[26] = {0};
        for (char c : str) ++count[c-'a'];

        priority_queue<pair<int, char>> heap;
        for (int i = 0; i < 26; i++) {
            heap.push(make_pair(count[i], 'a'+i));
        }

        int n = str.size(), m = (n+k-1)/k;
        int l1 = n%k ? n%k : k; // can have m same char
        int l2 = k-l1;          // can have m-1 same char
        if (heap.top().first > m) {
            return "";
        }

        int t1 = 0, t2 = 0;
        while (!heap.empty()) {
            int cnt = heap.top().first;
            char c = heap.top().second;
            heap.pop();
            if (cnt == m) {
                if (--l1 < 0) {
                    return "";
                }
            }

            while (cnt--) {
                str[t1] = c;
                t1 += k;
                if (t1 >= n) {
                    t1 = ++t2;
                }
            }
        }

        return str;
    }
};