class Solution {
private:
    void computePalindromes(string& s, vector<vector<bool>>& dp){
        int n = s.length();
        for (int i = 0; i < n; i++){
            dp[i][i] = true;
            if (i+1 < n) dp[i][i+1] = (s[i] == s[i+1]);
        }
        for (int len = 3; len <= n; len++){
            for (int i = 0, j; i <= n - len; i++){
                j = i + len - 1;
                dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
            }
        }
    }
    void backtrack(int index, string &s, vector<string>& curr, vector<vector<string>>& result, vector<vector<bool>>& dp){
        if (index >= s.length()){
            result.push_back(curr);
            return;
        }
        for (int i = index; i < s.length(); i++){
            if (dp[index][i]){
                curr.push_back(s.substr(index, i - index + 1));
                backtrack(i + 1, s, curr, result, dp);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        std::vector<vector<bool>> dp(n, vector<bool>(n, false));
        computePalindromes(s, dp);
        std::vector<vector<string>> result;
        std::vector<string> t;
        backtrack(0, s, t, result, dp);
        return result;
    }
};
