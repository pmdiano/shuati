// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        int mid;
        
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (isBadVersion(mid))
                end = mid - 1;
            else
                start = mid + 1;
        }
        
        return start;
    }
};