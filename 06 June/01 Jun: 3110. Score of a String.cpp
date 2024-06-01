class Solution {
public:
    int scoreOfString(string s) {
         int total = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            total += abs(s[i] - s[i + 1]);
        }
        return total;
    }
};
