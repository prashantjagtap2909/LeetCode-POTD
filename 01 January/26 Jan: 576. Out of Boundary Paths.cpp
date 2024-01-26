class Solution {
public:
    int mod = 1e9 + 7;
    int get(vector<vector<vector<int>>> &dp , int row , int col , int remMoves , int &m , int &n){
        if(remMoves < 0){
            return 0;
        }
        if(row < 0 or col < 0 or row == m or col == n){
            return 1;
        }
        if(dp[row][col][remMoves] != -1){
            return dp[row][col][remMoves];
        }
        long ans = 0;
        ans += get(dp , row , col+1 , remMoves-1 , m , n);
        ans += get(dp , row , col-1 , remMoves-1 , m , n);
        ans += get(dp , row-1 , col , remMoves-1 , m , n);
        ans += get(dp , row+1 , col , remMoves-1 , m , n);
        ans %= mod;
        return dp[row][col][remMoves] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp( m , vector<vector<int>> (n , vector<int> (maxMove+1,-1)));
        return get(dp , startRow , startColumn , maxMove , m , n);
    }
};
