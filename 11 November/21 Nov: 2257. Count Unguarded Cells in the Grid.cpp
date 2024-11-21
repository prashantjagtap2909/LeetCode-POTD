class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<pair<int, int>> dir = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto w : walls) {
            grid[w[0]][w[1]] = -1;
        }
        for (auto g : guards) {
            grid[g[0]][g[1]] = 2;
        }

        for (auto g : guards) {
            for (auto d : dir) {
                int x = g[0], y = g[1];
                while (true) {
                    x += d.first;
                    y += d.second;
                    if (x < 0 || x >= m || y < 0 || y >= n ||
                        grid[x][y] == -1 || grid[x][y] == 2) {
                        break;
                    }
                    if (grid[x][y] == 0) {
                        grid[x][y] = 1;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
