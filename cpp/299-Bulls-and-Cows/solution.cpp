class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        int A[10] = {0}, B[10] = {0};
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bull++;
            } else {
                A[secret[i] - '0']++;
                B[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            cow += min(A[i], B[i]);
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};