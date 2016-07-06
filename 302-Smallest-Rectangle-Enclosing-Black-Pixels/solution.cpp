class Solution {
    int binarySearch(vector<vector<char>>& image, int start, int end, int i1, int i2, bool isHorizontal, bool searchingBlack) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            bool hasBlack = false;
            for (int i = i1; i <= i2; i++) {
                if ((isHorizontal ? image[i][mid] : image[mid][i]) == '1') {
                    hasBlack = true;
                    break;
                }
            }

            if (hasBlack == searchingBlack) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.empty() || image[0].empty()) {
            return 0;
        }

        int rowNum = image.size(), colNum = image[0].size();
        int left = binarySearch(image, 0, y, 0, rowNum-1, true, true);
        int right = binarySearch(image, y, colNum-1, 0, rowNum-1, true, false);
        int top = binarySearch(image, 0, x, left, right, false, true);
        int bottom = binarySearch(image, x, rowNum-1, left, right, false, false);

        return (right-left)*(bottom-top);
    }
};