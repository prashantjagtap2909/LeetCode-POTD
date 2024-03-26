class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
       sort(v.begin(),v.end());
        int n=v.size();
        int i=0;
        while(i<n && v[i]<=0) {
            i++;
        }
        if(i==n)
            return 1;
        int c=1;
        while(i<n) {
            if(v[i]!=c)
                return c;
            while(i<n && v[i]==c) {
                i++;
            }
            c++;
        }
        return c;
    }
};
