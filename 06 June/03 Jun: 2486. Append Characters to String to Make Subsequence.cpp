class Solution {
public:
    int appendCharacters(string s, string t) {
        int sIndex = 0 , tIndex = 0;
        int n = s.length(), m = t.length();

        while(sIndex < n && tIndex < m){
            if(s[sIndex] == t[tIndex]){
                tIndex++;
            }
            sIndex++;
        }
        return m - tIndex;
    }
};
