class Solution {
public:
    int minimumLength(string str) {
        int s=0,e=str.size()-1; 
        while(s<e){
            if(str[s]==str[e]){
                while(str[s]==str[s+1] && s<e)s++;
                while(str[e]==str[e-1] && s<e)e--;
                s++;
                e--;
            }
            else break;
        }
        int ans=e-s+1;
        if(ans<0)return 0;
        return ans;
    }
};
