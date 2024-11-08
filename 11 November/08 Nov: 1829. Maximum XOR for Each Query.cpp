class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        nums[0]^=(1<<maximumBit)-1; 
        partial_sum(nums.begin(), nums.end(), nums.begin(), bit_xor<>());
        reverse(nums.begin(), nums.end());
        return nums;
    }
};
