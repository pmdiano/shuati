class Solution {
public:
    bool isMatch(string s, string p) {
        const char *sp = s.c_str(), *pp = p.c_str();
        const char *star = nullptr, *ss = nullptr;

        while (*sp) {
            if (*pp == '?' || *sp == *pp) { sp++; pp++; continue; }
            if (*pp == '*') { star = pp++; ss = sp; continue; }
            if (star) { pp = star + 1; sp = ++ss; continue; }
            return false;
        }

        while (*pp == '*') pp++;
        return !*pp;
    }
};
