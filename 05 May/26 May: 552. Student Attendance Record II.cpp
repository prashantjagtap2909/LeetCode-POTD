class Solution {
public:
    const long long mod=1e9+7;
    int checkRecord(int n) {
        int dp[100001][2][3]={0};
        fill(&dp[0][0][0], &dp[0][0][0]+6, 1);// dp[0][j][k]=1 for all j, k
        for(int i=1; i<=n; i++){
            for(int j=0; j<=1; j++){
                for(int k=0; k<=2; k++){
                    long long ans=dp[i-1][j][0];
                    ans+=(k<2?dp[i-1][j][k+1]:0);
                    ans+=(j==0?dp[i-1][j+1][0]:0);
                    dp[i][j][k]=ans%mod;
                }
            }
        }
        
        return dp[n][0][0];
    }
};
