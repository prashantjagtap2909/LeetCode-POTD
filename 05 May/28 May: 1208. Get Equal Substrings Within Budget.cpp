class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        const int n=s.size();
        vector<int> sum(n+1, 0);// 1-indexed prefix sum
        for(int i=0; i<n; i++)
            sum[i+1]=sum[i]+abs(s[i]-t[i]);
        
        int l=0, r, len=0;
        for(r=0; r<n; r++){
            int cost=sum[r+1]-sum[l];
            while (cost> maxCost) {
                cost=sum[r+1]-sum[++l];
            }
            len=max(len, r-l+1);
        }
        return len;
    }
};
