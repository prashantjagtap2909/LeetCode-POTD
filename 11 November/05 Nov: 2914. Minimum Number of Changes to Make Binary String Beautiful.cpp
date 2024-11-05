class Solution {
public:
    int minChanges(string s) {
        int n = s.size() , cnt = 0;
        for(int i = 0 ; i < n ; i+= 2){
            cnt += (s[i] != s[i+1]);
        }
        return cnt;
    }
};
