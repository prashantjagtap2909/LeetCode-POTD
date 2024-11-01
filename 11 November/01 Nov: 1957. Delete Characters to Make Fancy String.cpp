class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size(), i=0;
        char prev='@';
        for(int len=0; char c: s){
            if (prev!=c) len=1;
            else len++;
            if (len<= 2) 
                s[i++]=c;
            prev=c;
            
        }
        s.resize(i);
        return s;
    }
};
