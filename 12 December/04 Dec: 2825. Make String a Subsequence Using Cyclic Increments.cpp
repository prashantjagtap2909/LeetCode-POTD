class Solution {
public:
    bool canMakeSubsequence(string& str1, string& str2) {
        int n1=str1.size(), n2=str2.size();
        str2.push_back('@');
        char c2=str2[0];
        int i, j;
        for(i=0, j=0; i<n1 && j<n2; i++){
            char c1=str1[i];
            if (c1==c2 ||c1+1==c2 || (c1=='z' && c2=='a')) 
                c2=str2[++j];
        }
        return j==n2; 
    }
};
