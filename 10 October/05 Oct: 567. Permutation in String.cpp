class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map <char, int> m;
        int l1 = s1.size(), l2 = s2.size();
        for(auto c : s1) m[c]++;
        sort(s1.begin(), s1.end());
        int j=0;
        while(j < l2){
            if(l2-j < l1) return false;
            if( m.find( s2[j] ) != m.end() ){
                string sub = s2.substr(j, l1);
                sort(sub.begin(), sub.end());
                if(s1 == sub) return true;
            }
            j++;
        }
        return false;
    }
};
