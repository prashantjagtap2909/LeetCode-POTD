class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
    int m = grid[0].size();

    // Create 3D DP table with initial values of 0
    int dp[n][m][m];
    memset(dp, 0, sizeof(dp));

    // Set the starting point value (top-left and top-right corner)
    int cherries = 0;
    dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1]; // Add cherries from both robots
    // Iterate through each row from second onwards
    for (int i = 1; i < n; ++i) {
      // Iterate through each column for robot 1
      for (int j = 0; j < m; ++j) {
        // Iterate through each column for robot 2
        for (int k = 0; k < m; ++k) {
          
          if (j > i || k < m - i - 1 || j > k) continue;
          dp[i][j][k] = dp[i - 1][j][k];

          if (j - 1 >= 0) {
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k]);
          }

          if (j - 1 >= 0 && k - 1 >= 0)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1]);

          if (j - 1 >= 0 && k + 1 < m)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k + 1]);

          if (j + 1 < m) {
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + 1][k]);
          }

          if (j + 1 < m && k - 1 >= 0)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + 1][k - 1]);

          if (j + 1 < m && k + 1 < m)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + 1][k + 1]);

          if (k - 1 >= 0)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);

          if (k + 1 < m)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k + 1]);

          if (j != k) {
            dp[i][j][k] += grid[i][j] + grid[i][k];
          } else {
            dp[i][j][k] += grid[i][j]; 
          }
          cherries = max(cherries, dp[i][j][k]);
        }
      }
    }

    return cherries;
    }
};
