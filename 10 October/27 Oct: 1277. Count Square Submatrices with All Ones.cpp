class Solution {
public:
    int dp[300][300];
    int f(int i, int j, vector<vector<int>>& matrix){
        if (i<0||j<0|| matrix[i][j]==0 ) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=1+min({f(i-1, j, matrix),f(i-1, j-1, matrix),f(i, j-1, matrix)});
    }
    int countSquares(vector<vector<int>>& matrix) {
        const int r=matrix.size(), c=matrix[0].size();
        memset(dp, -1, sizeof(dp));
        int cnt=0;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                cnt+=f(i, j, matrix);
        return cnt;
    }
};
