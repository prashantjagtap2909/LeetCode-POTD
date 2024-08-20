class Solution {
public:
    vector<vector<vector<int>>> dp;
    int score(bool alice, int idx, int M, vector<int>& piles) {
        if (idx >= piles.size()) {
            return 0;
        }
        if (dp[alice][idx][M] != -1) {
            return dp[alice][idx][M];
        }
        int res = alice ? 0 : INT_MAX;
        int total = 0;
        for (int x = 1; x <= 2 * M; ++x) {
            if (idx + x > piles.size()) {
                break;
            }
            total += piles[idx + x - 1]; 
            if (alice) {
                res = max(res, total + score(!alice, idx + x, max(M, x), piles));
            } else {
                res = min(res, score(!alice, idx + x, max(M, x), piles));
            }
        }
        dp[alice][idx][M] = res;
        return res;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp = vector<vector<vector<int>>>(2, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return score(true, 0, 1, piles);
    }
};
