class Solution {
public:
    int M = 1e9+7;
    vector<int> dp;
    int solve(int low, int high, int zero, int one, int len) {
        if (len > high) return 0;
        if(dp[len] != -1) return dp[len];
        int got = 0;
        if(len >= low && len <= high) {
            got = 1;
        } 
        int addOne = solve(low, high, zero, one, len + one) % M;
        int addZero = solve(low, high, zero, one, len + zero) % M;
        return dp[len] = (got + addOne + addZero) % M;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.assign(100001, -1);
        return solve(low, high, zero, one, 0);
    }
};
