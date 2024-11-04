class Solution {
public:
    static string compressedString(string& word) {
        int n=word.size(), l=0;
        string ans;
        ans.reserve(n);
        for(int r=0; r<n; ){
            while( r<n && word[r]==word[l]) r++;

            auto [q, rem]=div(r-l, 9);
            
            for(int i=0; i<q; i++){
                ans.push_back('9');
                ans.push_back(word[l]);
            }
            if (rem>0) {
                ans.push_back(rem+'0');
                ans.push_back(word[l]);
            }
            l=r;
        }
        return ans;
    }
};
