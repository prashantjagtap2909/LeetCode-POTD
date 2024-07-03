class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 3) return 0;
        sort(begin(nums), end(nums));

        int ans = INT_MAX, n = nums.size();
        
        ans = min(ans, nums.back() - nums[3]);
        ans = min(ans, nums[n-4] - nums[0]);
        ans = min(ans, nums[n-2] - nums[2]);
        ans = min(ans, nums[n-3] - nums[1]);

        return ans;
    }
};
