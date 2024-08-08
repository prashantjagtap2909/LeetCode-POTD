class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        bool down = true, right = true;   
        int len = 2;
        int n = rows, m = cols, r = rStart, c = cStart;
        vector<vector<int>> ans(1, vector<int>({r, c}));

        int set1 = max(c+1, m-c+1), set2 = max(r+1, n-r+1);
        while (len <= max(2*set1, 2*set2)) {
            if (right && down) {
                int lim = c + len - 1;
                while (c < lim) {
                    c++;
                    if (r >= 0 && c >= 0 && r < n && c < m) {
                        ans.push_back({r, c});
                    }
                }
                right = !right;
            } else if (!right && down) {
                int lim = r + len - 1;
                while (r < lim) {
                    r++;
                    if (r >= 0 && c >= 0 && r < n && c < m) {
                        ans.push_back({r, c});
                    }
                }
                down = !down;
                len++;
            } else if (!right && !down) {
                int lim = c - len + 1;
                while (c > lim) {
                    c--;
                    if (r >= 0 && c >= 0 && r < n && c < m) {
                        ans.push_back({r, c});
                    }
                }
                right = !right;
            } else {
                int lim = r - len + 1;
                while (r > lim) {
                    r--;
                    if (r >= 0 && c >= 0 && r < n && c < m) {
                        ans.push_back({r, c});
                    }
                }
                down = !down;
                len++;
            }
        }
        return ans;
    }
};
