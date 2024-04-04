class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int opened = 0;

        for (char c : s) {
            if (c == '(') {
                opened++;
                res = max(res, opened);
            } else if (c == ')') {
                opened--;
            }
        }

        return res;
    }
};
