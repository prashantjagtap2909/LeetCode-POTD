class Solution {
public:
    char findKthBit(int n, int k) {
        return k==1?'0':(__builtin_popcount(k)==1?'1':'0'+1-(findKthBit(n, (1<<(32-__builtin_clz(k)))-k)-'0'));
    }
};
