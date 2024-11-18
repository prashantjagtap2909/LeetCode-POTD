class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0)
            return ans;
        for (int i = 0; i < n; i++) {
            code.push_back(code[i]);
        }
        if (k > 0) {
            vector<int> prefix(n + n, 0);
            prefix[0] = code[0];
            for (int i = 1; i < n + n; i++) {
                prefix[i] = prefix[i - 1] + code[i];
            }
            for (int i = 0; i < n; i++) {
                ans[i] = prefix[i + k] - prefix[i];
            }
            return ans;
        }
        vector<int> suffix(n + n, 0);
        suffix[n + n - 1] = code[n + n - 1];
        for (int i = n + n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + code[i];
        }
        for (int i = n; i < n + n; i++) {
            ans[i - n] = suffix[i + k] - suffix[i];
        }
        return ans;
    }
};
