class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);

        int overlap = 0;
        if (!(C <= E || G <= A)) { // x overlaps
            if (!(D <= F || H <= B)) { // y overlaps
                int overlap_x = min(C, G) - max(A, E);
                int overlap_y = min(D, H) - max(B, F);
                overlap = overlap_x * overlap_y;
            }
        }

        return area1 + area2 - overlap;
    }
};