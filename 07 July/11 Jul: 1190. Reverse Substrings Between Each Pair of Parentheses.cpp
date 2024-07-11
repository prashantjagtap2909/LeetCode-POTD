class Solution {
public:
    string reverseParentheses(string s) {
        string st, rev;
        for(char c: s){
            if (c!=')') st.push_back(c);
            else{
                rev="";
                char r=st.back();
                for(; r!='('; r=st.back()){
                    rev+=r;
                    st.pop_back();
                }
                st.pop_back();
                st+=rev;
            }
        }
        return st;
    }
};
