class Solution {
public:
    int dp[105][105];
    int solve(int index , int dial_index , string &ring , int n , string &key , int m)
    {
        if(index >= m)
        {
            return 0;
        }

        if(dp[index][dial_index] != -1)
        {
            return dp[index][dial_index];
        }

        int ans = 1e9;

        for(int k = 0 ; k < n ; k++)
        {
            int i = (index + k)%n;

            if(ring[i] == key[index])
            {
                int forw = abs(i - dial_index);
                int back = n - abs(i - dial_index);

                ans = min(ans , min(forw,back) + 1 + solve(index+1 , i , ring , n , key , m));
            }
        }

        return dp[index][dial_index] = ans;
    }
    int findRotateSteps(string ring, string key) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , ring , ring.size() , key , key.size());
    }
};
