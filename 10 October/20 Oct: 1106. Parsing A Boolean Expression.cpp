class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> oper;
        stack<char> st;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '|' || s[i] == '&' || s[i] == '!'){
                oper.push(s[i]);
            }
            else if(s[i] == 'f' || s[i] == 't' || s[i] == '(' || s[i] == ','){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                //not we need to evaluate
                char op = oper.top();
                oper.pop();
                if(op == '&'){
                    bool flag = true;
                    while(st.top()!='('){
                        char c = st.top();
                        if(c == 'f'){
                            flag = false;
                        }
                        st.pop();
                    }
                    st.pop();
                    if(flag) st.push('t');
                    else st.push('f');
                }
                else if(op == '|'){
                    bool flag = false;
                    while(st.top()!='('){
                        char c = st.top();
                        if(c == 't'){
                            flag = true;
                        }
                        st.pop();
                    }
                    st.pop();
                    if(flag) st.push('t');
                    else st.push('f');
                }
                else if(op == '!'){
                    char c = st.top();
                    st.pop();
                    st.pop();
                    if(c == 't'){
                        st.push('f');
                    }
                    else st.push('t');
                }
            }
        }
        if(st.top() == 'f') return false;
        else return true;
    }
};
