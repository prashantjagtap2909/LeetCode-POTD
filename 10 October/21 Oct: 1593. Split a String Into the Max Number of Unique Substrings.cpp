class Solution {
public:
    unordered_set<string> word;
    int n, maxCnt=0;
    void f(int i, int cnt, string& s){
        if (i>=n) {
            maxCnt=max(maxCnt, cnt);
            return ;
        }
        for(int j=i; j<n; j++){
            string t=s.substr(i, j-i+1);
            if (word.count(t)) continue;
            word.insert(t);
            f(j+1, cnt+1, s);
            word.erase(t);// backtrack
        }

    }
    int maxUniqueSplit(string& s) {
        n=s.size();
        word.reserve(n);
        int cnt=0;
        f(0, cnt, s);
        return maxCnt;  
    }
};
