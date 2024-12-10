class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int l = 1, r = n;

        if (!helper(s, n, l)) return -1;

        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (helper(s, n, mid)) l = mid;
            else r = mid;
        }

        return l;
    }

private:
    bool helper(const string& s, int n, int x) {
        vector<int> cnt(26, 0);
        int p = 0;

        for (int i = 0; i < n; i++) {
            while (s[p] != s[i]) p++;
            if (i - p + 1 >= x) cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] > 2) return true;
        }

        return false;
    }
};
