class Solution {
public:
    int minimumDeletions(string s) {
         const int n=s.size();
        int B_pre=s[0]=='b';
        int A_suf=count(s.begin(), s.end(), 'a');// Count 'a' in s
        int cnt=B_pre+A_suf-1;
        for(int i=1; i<n; i++){
            B_pre+=(s[i]=='b');
            A_suf-=(s[i-1]=='a');
            cnt=min(cnt, B_pre+A_suf-1);
        }
        return cnt;
    }
};
