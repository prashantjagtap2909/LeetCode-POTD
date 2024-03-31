class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int left = 0;
        int pmin = -1;
        int pmax = -1;

        for (int right = 0; right < nums.size(); right++) {
            int num = nums[right];
            if (num < minK || num > maxK) {
                left = right + 1;
                pmin = -1;
                pmax = -1;
            } else {
                if (num == minK) pmin = right;
                if (num == maxK) pmax = right;
                res += max(0, min(pmin, pmax) - left + 1);
            }   
        }

        return res;
    }
};
