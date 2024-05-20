class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i = 0 ; i < ( 1 << n);i++){
            int sub = 0;
            for(int j = 0 ; j < n ; j++){
                if ( i & ( 1 << j)){
                    sub ^= nums[j];
                }
            }
            total += sub;
        }
        return total;
    }
};
