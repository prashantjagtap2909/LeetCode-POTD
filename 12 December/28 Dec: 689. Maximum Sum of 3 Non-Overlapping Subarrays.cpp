class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), sum1 = 0, sum2 = 0, sum3 = 0;
        int max1 = 0, max12 = 0, max123 = 0;
        int index1 = 0, index12_1 = 0, index12_2 = k;
        vector<int> ans = {0, k, 2 * k};

        for (int i = 0; i < k; i++) {
            sum1 += nums[i];
            sum2 += nums[i + k];
            sum3 += nums[i + 2 * k];
        }
        max1 = sum1;
        max12 = sum1 + sum2;
        max123 = sum1 + sum2 + sum3;

        for (int i = 0; i <= n - 3 * k; i++) {
            if (i > 0) {
                sum1 = sum1 - nums[i - 1] + nums[i + k - 1];
                sum2 = sum2 - nums[i + k - 1] + nums[i + 2 * k - 1];
                sum3 = sum3 - nums[i + 2 * k - 1] + nums[i + 3 * k - 1];
            }

            if (sum1 > max1) {
                max1 = sum1;
                index1 = i;
            }

            if (max1 + sum2 > max12) {
                max12 = max1 + sum2;
                index12_1 = index1;
                index12_2 = i + k;
            }

            if (max12 + sum3 > max123) {
                max123 = max12 + sum3;
                ans = {index12_1, index12_2, i + 2 * k};
            }
        }

        return ans;
    }
};
