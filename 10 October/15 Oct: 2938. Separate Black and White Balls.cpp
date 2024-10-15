class Solution {
public:
    long long minimumSteps(string s) {
        long long w = 0, res = 0, n=s.length();

        for(int i= 0 ; i < n ; i++){
            if(s[i] == '0'){
                res += w;
            }else if(s[i] == '1'){
                w++;
            }
        }
        return res;
    }
};
