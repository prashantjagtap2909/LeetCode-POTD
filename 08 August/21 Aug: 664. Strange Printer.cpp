class Solution {
    int dp[101][101];
private:
    int f(int i, int j, string& s){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int steps = 1 + f(i+1,j,s);
        for(int k=i+1; k<=j; k++){
            if(s[k]==s[i]){
                steps = min(steps, f(i,k-1,s)+f(k+1,j,s));
            }
        }

        return dp[i][j] = steps;
    }
public:
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        return f(0,s.size()-1,s);
    }
};
