// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans, count = 0;
        ans = start ^ goal; // will tell where they diff

        for (int i = 0; i < 31; i++) {
            if (ans & (1 << i)) count++; // helps to do AND with ith bit only by left-shift 1 i times
        }

        return count;
    }
};
