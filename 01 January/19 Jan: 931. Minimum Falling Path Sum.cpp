class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int dp[n+1][n+1];
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i<n;i++){
            dp[0][i] = arr[0][i];
        }
        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
                int v1 = 1e9,v2=1e9,v3=1e9;
                if(j>0){
                    v1 = dp[i-1][j-1]+arr[i][j];
                }
                v2 = dp[i-1][j]+arr[i][j];
                if(j<n-1){
                    v3 = dp[i-1][j+1]+arr[i][j];
                }
                int mn = min(v1,v2);
                mn = min(mn,v3);
                dp[i][j] = mn;
            }
        }
        int ans = 1e9;
        for(int i = 0;i<n;i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};
