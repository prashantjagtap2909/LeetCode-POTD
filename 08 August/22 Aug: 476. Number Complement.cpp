class Solution {
public:
    static int findComplement(long long num) {
         if (num == 0) return 1; 
        unsigned int bitmask = ~0; 
        while (num & bitmask) {
            bitmask <<= 1;
        }
        return num ^ ~bitmask;
    }
};
