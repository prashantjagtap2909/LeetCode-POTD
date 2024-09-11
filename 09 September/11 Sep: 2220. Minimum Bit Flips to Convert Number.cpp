class Solution {
public:
    int minBitFlips(int x, int y) {
        return bitset<32>(x^y).count();
    }
};
