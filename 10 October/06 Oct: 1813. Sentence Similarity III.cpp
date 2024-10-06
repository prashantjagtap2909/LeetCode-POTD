class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
    
    vector<string> s1, s2;
    sentence1.push_back(' ');
    sentence2.push_back(' ');
    string ans = "";

    for(int i=0; i<sentence1.size(); i++){
        if(sentence1[i] == ' '){
            s1.push_back(ans); 
            ans = "";
        }
        else{
            ans.push_back(sentence1[i]);
        }
    }
        for(int i = 0; i<sentence2.size(); i++){
            if(sentence2[i] == ' '){
                s2.push_back(ans);
                ans = "";
            }
            else{
                ans.push_back(sentence2[i]);
            }
        }
       int m1 = 0, m2 = 0;
       int n1 = s1.size() - 1, n2 = s2.size() - 1;
       while(m1 <= n1 && m2 <= n2){
        if(s1[m1] == s2[m2]){
            m1++;m2++;
        }else if(s1[n1] == s2[n2]){
            n1--; n2--;
        }else break;
       }
      return(n1 + 1 == m1 || n2 +1 == m2) ? true:false;
    }
};
