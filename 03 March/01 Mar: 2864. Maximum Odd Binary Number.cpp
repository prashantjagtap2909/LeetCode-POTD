class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        return string(count(s.begin(), s.end(), '1')-1, '1')+string(count(s.begin(), s.end(), '0'), '0')+'1';
    }
};
