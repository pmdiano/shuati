class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);

        int overlap = 0;
        if (!(C <= E || G <= A)) { // x overlaps
            if (!(D <= F || H <= B)) { // y overlaps
                int overlap_x = 0, overlap_y = 0;

                if (E <= A && G <= C) {
                    overlap_x = G - A;
                } else if (E <= A && G >= C) {
                    overlap_x = C - A;
                } else if (A <= E && G <= C) {
                    overlap_x = G - E;
                } else if (A <= E && G >= C) {
                    overlap_x = C - E;
                }

                if (F <= B && H <= D) {
                    overlap_y = H - B;
                } else if (F <= B && H >= D) {
                    overlap_y = D - B;
                } else if (B <= F && H <= D) {
                    overlap_y = H - F;
                } else if (B <= F && H >= D) {
                    overlap_y = D - F;
                }

                overlap = overlap_x * overlap_y;
            }
        }

        return area1 + area2 - overlap;
    }
};