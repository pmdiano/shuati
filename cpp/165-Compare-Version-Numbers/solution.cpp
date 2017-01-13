class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0, j1 = 0, i2 = 0, j2 = 0, v1, v2;
        while (i1 < version1.length() || i2 < version2.length()) {
            if (i1 < version1.length()) {
                while (version1[i1] && version1[i1] != '.') i1++;
                char c = version1[i1];
                version1[i1] = '\0';
                v1 = atoi(const_cast<char*>(version1.c_str()) + j1);
                version1[i1] = c;
            } else {
                v1 = 0;
            }

            if (i2 < version2.length()) {
                while (version2[i2] && version2[i2] != '.') i2++;
                char c = version2[i2];
                version2[i2] = '\0';
                v2 = atoi(const_cast<char*>(version2.c_str()) + j2);
                version2[i2] = c;
            } else {
                v2 = 0;
            }

            if (v1 != v2) {
                return v1 > v2 ? 1 : -1;
            }
            i1++, i2++;
            j1 = i1, j2 = i2;
        }
        return 0;
    }
};