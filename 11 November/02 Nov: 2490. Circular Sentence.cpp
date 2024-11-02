class Solution {
public:
    bool isCircularSentence(string& s) {
        return s[0]==s.back() && all_of(s.begin(), s.end(), [&, i=0](auto _) mutable{
            return !i++|| s[i]!=' ' || s[i-1]==s[i+1];
        });
    }
};
