class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bitset<20>xorSum = k;
        for(auto x:nums){
            xorSum ^= x;
        }
        return xorSum.count();
    }
};
