class Solution {
public:
    int st[5001];
    int top=-1;
    void operation(string& op){
        if (top==-1) return;
        int n2=st[top--];
        if (top==-1) return;
        int n1=st[top--];
        int x;
        switch(op[0]){
            case '+': x=n1+n2; break;
            case '-': x=n1-n2; break;
            case '*': x=n1*n2; break;
            case '/': x=n1/n2; break;
        }
        st[++top]=x;
    }
    int evalRPN(vector<string>& tokens) {
        for(string& s: tokens){
             if (s.size()>1 || isdigit(s[0])){
                int x=stoi(s);
                st[++top]=x;
            }
            else operation(s);  
        }
        
        if (top==-1) return 0;
        
        return st[top];
    }
};
