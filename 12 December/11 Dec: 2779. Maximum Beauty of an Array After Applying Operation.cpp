class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int maxValue = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
            }
        }
        vector<int> range(maxValue + 10, 0);
        for (int i = 0; i < n; i++) {
            int left = max(0, nums[i] - k);
            int right = min(maxValue, nums[i] + k) + 1;
            range[left]++;
            range[right]--;
        }
        int result = range[0];
        for (int i = 1; i < range.size(); i++) {
            range[i] += range[i - 1];
            if (range[i] > result) {
                result = range[i];
            }
        }
        return result;
    }
};
