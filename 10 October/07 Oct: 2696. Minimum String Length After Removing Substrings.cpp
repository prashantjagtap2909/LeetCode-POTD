class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        if (n < 2)
            return n;
        int write = 0, read = 0;
        while (read < s.length()) {
            s[write] = s[read];
            if (write > 0 && (s[write - 1] == 'A' || s[write - 1] == 'C') && (s[write] - 'A') == (s[write - 1] - 'A' + 1)) {
                write--; 
            } else {
                write++;
            }
            read++;
        }
        return write;
    }
};
