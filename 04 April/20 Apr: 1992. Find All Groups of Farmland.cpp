class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        int m = land.size();
        int n = land[0].size();
        
        auto findFarmlandCoordinates = [&](int row, int col) {
            vector<int> coordinates = {row, col};
            int r = row, c = col;
            
            while (r < m && land[r][col] == 1) r++;
            while (c < n && land[row][c] == 1) c++;
            
            coordinates.push_back(r - 1);
            coordinates.push_back(c - 1);
            
            for (int i = row; i <= r - 1; i++) {
                for (int j = col; j <= c - 1; j++) {
                    land[i][j] = 0;
                }
            }
            
            return coordinates;
        };
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    result.push_back(findFarmlandCoordinates(i, j));
                }
            }
        }
        
        return result;
    }
};
