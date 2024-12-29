class Solution {
public:
    const int MOD = 1e9 + 7;
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int m = target.size();
        vector<unordered_map<char, int>> freq(n);
        for (const string& word : words) {
            for (int i = 0; i < n; i++) {
                freq[i][word[i]]++;
            }
        }
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        function<int(int, int)> traverse = [&](int level, int index) -> int {
            if (index == m) return 1;
            if (level == n) return 0;
            if (memo[level][index] != -1) return memo[level][index];
            int ways = traverse(level + 1, index);
            if (freq[level].count(target[index])) {
                long long count = freq[level][target[index]];
                ways = (ways + count * traverse(level + 1, index + 1)) % MOD;
            }
            return memo[level][index] = ways;
        };
        return traverse(0, 0);
    }
};
