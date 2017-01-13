// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {

public:
    int findCelebrity(int n) {
        if (n <= 0) return -1;
        if (n == 1) return 0;

        vector<int> people(n);
        for (int i = 0; i < n; i++) {
            people[i] = i;
        }

        int m = n, candidate = -1;
        for (;;) {
            bool last = knows(people[m-1], people[0]);
            int j = 0;
            for (int i = 0; i < m; i++) {
                bool b = knows(people[i], people[(i+1)%m]);
                if (last && !b) {
                    people[j++] = people[i];
                }
                last = b;
            }

            if (j == m || j == 0) {
                return -1;
            }
            if (j == 1) {
                candidate = people[0];
                break;
            }
            m = j;
        }

        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;
            if (!knows(i, candidate) || knows(candidate, i)) {
                return -1;
            }
        }

        return candidate;
    }
};