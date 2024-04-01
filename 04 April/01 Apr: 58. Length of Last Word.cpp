class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int count = 0 ;
        int ans=0;
        for(int i = n-1 ; i>=0 ; i--)
        {
        if(s[i]==' ') count++;
        else break;
        }
        for(int i = n-1-count ; i>=0 ; i--)
        {
            if(s[i]!=' ') ans++;
            else break;
        }
        return ans;
    }
};
