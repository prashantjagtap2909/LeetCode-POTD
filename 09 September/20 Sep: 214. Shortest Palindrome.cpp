class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size(), i = 0;
        for (int j=n-1; j>= 0; j--) {
            while (j>=0 && s[i] == s[j])
                i++, j--;
        }
        if (i==n) 
            return s;
        string temp= s.substr(i), remain_rev=temp;
        reverse(remain_rev.begin(), remain_rev.end());
        return remain_rev + shortestPalindrome(s.substr(0, i)) + temp;
    }
};
