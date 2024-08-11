class Solution {
public:
    void dfs(vector<vector<int>>& mat, int i, int j) {
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() ||
            mat[i][j] == 0)
            return;
        mat[i][j] = 0;
        dfs(mat, i + 1, j);
        dfs(mat, i - 1, j);
        dfs(mat, i, j + 1);
        dfs(mat, i, j - 1);
    }
    int countIslands(vector<vector<int>> grid) {
        int isl = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    isl++;
                    dfs(grid, i, j);
                }
            }
        }
        return isl;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = countIslands(grid);
        if(n > 1 || n == 0) return 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int isl = countIslands(grid);
                    if(isl>1 || isl==0) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
