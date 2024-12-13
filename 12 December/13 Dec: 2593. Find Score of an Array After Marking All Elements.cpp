class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] <= nums[i + 1]) {
                res += nums[i];
                nums[i + 1] = INT_MAX;
                nums[i] = INT_MAX;
                nums[max(i - 1, 0)] = INT_MAX;
            }
        }
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] < nums[i - 1]) {
                res += nums[i];
                nums[i - 1] = INT_MAX;
            }
        }
        res=nums[0]==INT_MAX?res:nums[0]+res;
        return res;
    }
};
