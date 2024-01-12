class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int first = 0;
        int second = 0;
        set<char> v = {'a','e','i','o','u','A','E','I','O','U'};
        for(int i = 0;i<n;i++){
            if(i<n/2){
                if(v.find(s[i])!=v.end()){
                    first++;
                }
            }else{
                if(v.find(s[i])!=v.end()){
                    second++;
                }
            }
        }
        return first==second;
    }
};
