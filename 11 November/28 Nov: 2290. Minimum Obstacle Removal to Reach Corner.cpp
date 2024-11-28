
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n_rows = grid.size();
        int n_cols = grid[0].size();
        vector<pair<int, int>> diffs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        deque<pair<int, int>> in_progress;
        vector<vector<int>> distance(n_rows, vector<int>(n_cols, INT_MAX));
        in_progress.push_front({0, 0});
        distance[0][0] = 0;
        while (!in_progress.empty()) {
            auto [i, j] = in_progress.front();
            in_progress.pop_front();
            for (const auto& [di, dj] : diffs) {
                int new_i = i + di;
                int new_j = j + dj;
                if (new_i >= 0 && new_i < n_rows && new_j >= 0 && new_j < n_cols) {
                    int new_distance = distance[i][j] + grid[new_i][new_j];
                    if (new_distance < distance[new_i][new_j]) {
                        distance[new_i][new_j] = new_distance;
                        if (grid[new_i][new_j] == 0) {
                            in_progress.push_front({new_i, new_j});
                        } else {
                            in_progress.push_back({new_i, new_j});
                        }
                    }
                }
            }
        }
        return distance[n_rows - 1][n_cols - 1];
    }
};
