class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg = 0;
        long long minVal = LLONG_MAX;
        long long sum = 0;

        for (const auto& vec : matrix) {
            for (const auto& val : vec) {
                if (val < 0) {
                    neg++;
                }
                sum += abs(val);
                minVal = min(minVal, (long long)abs(val));
            }
        }
        if (neg % 2 == 1) {
            sum -= 2LL * minVal;
        }
        return sum;
    }
};
