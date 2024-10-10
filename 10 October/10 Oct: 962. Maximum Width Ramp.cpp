class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> monoStack;
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (monoStack.empty() || nums[monoStack.top()] > nums[i]) {
                monoStack.push(i);
            }
        }
        for (int j = n - 1; j >= 0; --j) {
            while (!monoStack.empty() && nums[j] >= nums[monoStack.top()]) {
                result = max(result, j - monoStack.top());
                monoStack.pop();
            }
        }

        return result;
    }
};
