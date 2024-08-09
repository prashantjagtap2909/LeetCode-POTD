class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int row, int col)
    {
        set<int>st;
        int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        for(int i=row;i<row+3;i++)
        {
            int rowSum = 0;
            for(int j=col;j<col+3;j++)
            {
                st.insert(grid[i][j]);
                rowSum += grid[i][j];
            }
            if(sum != rowSum) return false;
        }
        for(int j=col;j<col+3;j++)
        {
            int colSum = 0;
            for(int i=row;i<row+3;i++)
                colSum += grid[i][j];
            if(sum != colSum) return false;
        }
        if (grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2] != sum) return false;
        if (grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col] != sum) return false;
        for(int i=1;i<10;i++)
            if(not st.count(i)) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        int ans = 0, n = grid.size(), m = grid[0].size();
        for(int i=0;i<n-2;i++)
            for(int j=0;j<m-2;j++)
                ans += isMagic(grid, i, j);
        return ans;
    }
};
